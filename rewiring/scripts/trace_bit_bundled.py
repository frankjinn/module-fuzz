#!/usr/bin/env python3
"""
Bundled bit tracer - groups bits with the same logical operation
Dramatically simplifies the graph by showing ranges instead of individual bits
"""

import re
import sys
import argparse
from collections import defaultdict, deque
import networkx as nx
import matplotlib.pyplot as plt
import matplotlib.patches as mpatches
from pathlib import Path

class BundledBitTracer:
    def __init__(self, top_filepath, module_dir):
        self.top_filepath = top_filepath
        self.module_dir = Path(module_dir)
        self.bit_connections = {}
        self.modules = {}
        self.wrapper_cache = {}
        self.logic_cache = {}
        self.parse_top()
    
    def parse_top(self):
        """Parse top.sv"""
        with open(self.top_filepath, 'r') as f:
            content = f.read()
        
        module_pattern = r'wire \[(\d+):(\d+)\] (\w+)_(in|out)_flat;'
        for match in re.finditer(module_pattern, content):
            high, low, module_name, port_type = match.groups()
            if module_name not in self.modules:
                self.modules[module_name] = {'in_width': 0, 'out_width': 0}
            width = int(high) - int(low) + 1
            if port_type == 'in':
                self.modules[module_name]['in_width'] = width
            else:
                self.modules[module_name]['out_width'] = width
        
        assignment_pattern = r'assign\s+(\w+)\[(\d+)\]\s*=\s*(\w+)\[(\d+)\];'
        for match in re.finditer(assignment_pattern, content):
            target, target_bit, source, source_bit = match.groups()
            self.bit_connections[(target, int(target_bit))] = (source, int(source_bit))
    
    def parse_wrapper(self, module_name):
        """Parse wrapper"""
        if module_name in self.wrapper_cache:
            return self.wrapper_cache[module_name]
        
        wrapper_file = self.module_dir / "flattened" / f"{module_name}.sv"
        if not wrapper_file.exists():
            return None
        
        with open(wrapper_file, 'r') as f:
            content = f.read()
        
        mapping = {'inputs': {}, 'outputs': {}}
        
        # Parse inputs
        for match in re.finditer(r'wire\s+\[(\d+):(\d+)\]\s+(\w+)\s*=\s*in_flat\[(\d+):(\d+)\]', content):
            sig_high, sig_low, sig_name, flat_high, flat_low = match.groups()
            for i in range(int(flat_high) - int(flat_low) + 1):
                mapping['inputs'][int(flat_low) + i] = (sig_name, int(sig_low) + i)
        
        for match in re.finditer(r'wire\s+(\w+)\s*=\s*in_flat\[(\d+)\]', content):
            sig_name, flat_bit = match.groups()
            mapping['inputs'][int(flat_bit)] = (sig_name, 0)
        
        # Parse outputs
        for match in re.finditer(r'assign\s+out_flat\[(\d+):(\d+)\]\s*=\s*(\w+)', content):
            flat_high, flat_low, sig_name = match.groups()
            for i in range(int(flat_high) - int(flat_low) + 1):
                mapping['outputs'][int(flat_low) + i] = (sig_name, i)
        
        for match in re.finditer(r'assign\s+out_flat\[(\d+)\]\s*=\s*(\w+)', content):
            flat_bit, sig_name = match.groups()
            mapping['outputs'][int(flat_bit)] = (sig_name, 0)
        
        self.wrapper_cache[module_name] = mapping
        return mapping
    
    def parse_module_logic(self, module_name):
        """Parse module logic"""
        base_name = module_name.replace('_wrapper', '')
        
        if base_name in self.logic_cache:
            return self.logic_cache[base_name]
        
        module_file = self.module_dir / "unflattened" / f"{base_name}.sv"
        if not module_file.exists():
            return None
        
        with open(module_file, 'r') as f:
            content = f.read()
        
        expressions = {}
        for match in re.finditer(r'assign\s+(\w+)\s*=\s*([^;]+);', content):
            output, expression = match.groups()
            expressions[output] = expression.strip()
        
        self.logic_cache[base_name] = expressions
        return expressions
    
    def get_bit_dependencies(self, module_name, output_flat_bit):
        """Get exact input flat bits and expression for an output bit"""
        wrapper = self.parse_wrapper(module_name)
        if not wrapper or output_flat_bit not in wrapper['outputs']:
            return None
        
        output_signal, output_bit = wrapper['outputs'][output_flat_bit]
        expressions = self.parse_module_logic(module_name)
        if not expressions or output_signal not in expressions:
            return None
        
        expression = expressions[output_signal]
        
        # Extract input signals from expression
        identifiers = re.findall(r'\b[a-zA-Z_]\w*\b', expression)
        keywords = {'assign', 'wire', 'reg', 'input', 'output'}
        input_signals = [id for id in identifiers if id not in keywords and id != output_signal]
        
        # Determine if it's a bitwise operation (element-wise on vectors)
        is_bitwise = any(op in expression for op in ['&', '|', '^', '~']) and '[' not in expression
        
        input_flat_bits = set()
        input_bit_mapping = {}  # flat_bit -> (signal_name, signal_bit) for expression building
        
        if is_bitwise:
            # Bitwise: only corresponding bit of each input
            for sig in input_signals:
                for flat_bit, (s, sb) in wrapper['inputs'].items():
                    if s == sig and sb == output_bit:
                        input_flat_bits.add(flat_bit)
                        input_bit_mapping[flat_bit] = (sig, sb)
        else:
            # Non-bitwise: all bits of input signals
            for sig in input_signals:
                for flat_bit, (s, sb) in wrapper['inputs'].items():
                    if s == sig:
                        input_flat_bits.add(flat_bit)
                        input_bit_mapping[flat_bit] = (sig, sb)
        
        # Build expression with actual flat bit indexes (using Verilog notation)
        expr_with_bits = expression
        for sig in sorted(input_signals, key=len, reverse=True):  # Replace longer names first
            # Find the flat bits for this signal
            sig_flat_bits = [fb for fb in input_flat_bits if input_bit_mapping.get(fb, (None,))[0] == sig]
            if sig_flat_bits:
                if len(sig_flat_bits) == 1:
                    bit_str = f"in[{sig_flat_bits[0]}]"
                else:
                    # Use Verilog notation [high:low]
                    bit_str = f"in[{max(sig_flat_bits)}:{min(sig_flat_bits)}]"
                expr_with_bits = re.sub(r'\b' + sig + r'\b', bit_str, expr_with_bits)
        
        # Add output bit information to show which bit of the result is being used
        if is_bitwise:
            # For bitwise operations, show which bit index
            full_expr = f"out_bit[{output_bit}] = {expr_with_bits}[{output_bit}]"
        else:
            # For non-bitwise, show which bit of the result
            full_expr = f"out_bit[{output_bit}] = ({expr_with_bits})[{output_bit}]"
        
        return {
            'input_bits': input_flat_bits,
            'expression': expression,
            'expression_with_bits': expr_with_bits,
            'full_expression': full_expr,
            'output_signal': output_signal,
            'output_bit': output_bit,
            'is_bitwise': is_bitwise,
            'input_mapping': input_bit_mapping
        }
    
    def trace_and_bundle(self, signal_name, bit_index):
        """Trace and create bundled graph"""
        # First, do individual bit trace
        individual_deps = {}  # (signal, bit) -> set of (source_signal, source_bit)
        queue = deque([(signal_name, bit_index)])
        visited = set()
        
        while queue:
            current_signal, current_bit = queue.popleft()
            if (current_signal, current_bit) in visited:
                continue
            visited.add((current_signal, current_bit))
            
            if (current_signal, current_bit) not in individual_deps:
                individual_deps[(current_signal, current_bit)] = set()
            
            # Wire connections
            if (current_signal, current_bit) in self.bit_connections:
                source_signal, source_bit = self.bit_connections[(current_signal, current_bit)]
                individual_deps[(current_signal, current_bit)].add((source_signal, source_bit))
                queue.append((source_signal, source_bit))
            
            # Module internals
            if current_signal.endswith('_out_flat'):
                module_name = current_signal[:-9]
                result = self.get_bit_dependencies(module_name, current_bit)
                
                if result and result['input_bits']:
                    module_input_signal = f"{module_name}_in_flat"
                    for input_bit in result['input_bits']:
                        individual_deps[(current_signal, current_bit)].add(
                            (module_input_signal, input_bit))
                        queue.append((module_input_signal, input_bit))
        
        # Now bundle bits with similar patterns
        bundled_graph = self.create_bundled_graph(individual_deps, signal_name, bit_index)
        return bundled_graph, visited
    
    def create_bundled_graph(self, individual_deps, target_signal, target_bit):
        """Create bundled graph from individual dependencies"""
        G = nx.DiGraph()
        
        # Group bits by their EXACT connectivity pattern
        # Only bundle bits that have identical source/target relationships
        connectivity_signature = {}  # (signal, bit) -> frozenset of sources (for hashing)
        
        for (signal, bit), sources in individual_deps.items():
            sig = frozenset(sources)
            connectivity_signature[(signal, bit)] = sig
        
        # Group bits with identical connectivity
        equiv_classes = defaultdict(list)  # connectivity_sig -> list of (signal, bit)
        for (signal, bit), sig in connectivity_signature.items():
            equiv_classes[(signal, sig)].append(bit)
        
        # Create nodes - one per equivalence class
        signal_ranges = defaultdict(set)  # signal_name -> set of bits
        
        for (signal, bit), sources in individual_deps.items():
            signal_ranges[signal].add(bit)
        
        # Also include all source signals
        for (signal, bit), sources in individual_deps.items():
            for source_sig, source_bit in sources:
                signal_ranges[source_sig].add(source_bit)
        
        # Convert sets to ranges
        def bits_to_ranges(bits):
            """Convert set of bits to list of ranges"""
            if not bits:
                return []
            sorted_bits = sorted(bits)
            ranges = []
            start = sorted_bits[0]
            end = sorted_bits[0]
            
            for bit in sorted_bits[1:]:
                if bit == end + 1:
                    end = bit
                else:
                    ranges.append((start, end))
                    start = bit
                    end = bit
            ranges.append((start, end))
            return ranges
        
        # Create bundled nodes
        bundled_nodes = {}  # (signal, range_tuple) -> node_id
        
        for signal, bits in signal_ranges.items():
            ranges = bits_to_ranges(bits)
            for start, end in ranges:
                if start == end:
                    node_id = f"{signal}[{start}]"
                else:
                    node_id = f"{signal}[{end}:{start}]"
                
                # Determine node type
                module_name = None
                if signal == 'in_flat':
                    node_type = 'external_input'
                elif signal == 'out_flat':
                    node_type = 'external_output'
                elif signal.endswith('_in_flat'):
                    node_type = 'module_input'
                    module_name = signal[:-8]
                elif signal.endswith('_out_flat'):
                    node_type = 'module_output'
                    module_name = signal[:-9]
                else:
                    node_type = 'unknown'
                
                G.add_node(node_id,
                          signal=signal,
                          bit_range=(start, end),
                          node_type=node_type,
                          module=module_name if module_name else 'N/A')
                
                bundled_nodes[(signal, start, end)] = node_id
        
        # Create edges - track INDIVIDUAL bit connections for wire labels
        edge_connections = defaultdict(lambda: defaultdict(set))  # (src_node, tgt_node) -> data
        wire_bit_mappings = defaultdict(list)  # (src_node, tgt_node) -> list of (src_bit, tgt_bit)
        
        for (target_sig, target_bit), sources in individual_deps.items():
            # Find which bundle this target bit belongs to
            target_node = None
            for (sig, start, end), nid in bundled_nodes.items():
                if sig == target_sig and start <= target_bit <= end:
                    target_node = nid
                    break
            
            if not target_node:
                continue
            
            # Find source bundles and get expressions
            for source_sig, source_bit in sources:
                source_node = None
                for (sig, start, end), nid in bundled_nodes.items():
                    if sig == source_sig and start <= source_bit <= end:
                        source_node = nid
                        break
                
                if source_node:
                    # Get expression if going through module
                    if target_sig.endswith('_out_flat'):
                        module_name = target_sig[:-9]
                        result = self.get_bit_dependencies(module_name, target_bit)
                        if result:
                            # Use full expression showing output bit selection
                            full_expr = result.get('full_expression', result.get('expression_with_bits', result['expression']))
                            edge_connections[(source_node, target_node)]['expr'].add(full_expr)
                            edge_connections[(source_node, target_node)]['type'].add('module')
                        else:
                            edge_connections[(source_node, target_node)]['type'].add('wire')
                            wire_bit_mappings[(source_node, target_node)].append((source_bit, target_bit))
                    else:
                        edge_connections[(source_node, target_node)]['type'].add('wire')
                        wire_bit_mappings[(source_node, target_node)].append((source_bit, target_bit))
        
        # Add edges to graph with EXACT bit-to-bit wire labels
        for (src, tgt), data in edge_connections.items():
            if 'module' in data['type']:
                expressions = data.get('expr', set())
                if expressions:
                    expr = list(expressions)[0]  # Take first expression
                    # Simplify if too long
                    if len(expr) > 60:
                        expr = expr[:57] + "..."
                    G.add_edge(src, tgt, edge_type='module', expression=expr)
                else:
                    G.add_edge(src, tgt, edge_type='module', expression='logic')
            else:
                # For wire connections, detect and show range mappings
                mappings = wire_bit_mappings.get((src, tgt), [])
                
                if mappings:
                    # Sort mappings
                    mappings_sorted = sorted(set(mappings))
                    
                    if len(mappings_sorted) == 1:
                        # Single bit connection
                        src_b, tgt_b = mappings_sorted[0]
                        wire_label = f"[{src_b}]→[{tgt_b}]"
                    else:
                        # Detect continuous ranges
                        ranges = []
                        current_range_start = 0
                        current_range_end = 0
                        
                        for i in range(len(mappings_sorted)):
                            src_b, tgt_b = mappings_sorted[i]
                            
                            if i == 0:
                                current_range_start = i
                                current_range_end = i
                            else:
                                prev_src, prev_tgt = mappings_sorted[i-1]
                                # Check if continuous in both source and target
                                if src_b == prev_src + 1 and tgt_b == prev_tgt + 1:
                                    current_range_end = i
                                else:
                                    # End current range, start new one
                                    ranges.append((current_range_start, current_range_end))
                                    current_range_start = i
                                    current_range_end = i
                        
                        # Add final range
                        ranges.append((current_range_start, current_range_end))
                        
                        # Build label from ranges
                        range_labels = []
                        for start_idx, end_idx in ranges:
                            if start_idx == end_idx:
                                # Single bit
                                src_b, tgt_b = mappings_sorted[start_idx]
                                range_labels.append(f"[{src_b}]→[{tgt_b}]")
                            else:
                                # Continuous range - use Verilog notation [high:low]
                                src_start, tgt_start = mappings_sorted[start_idx]
                                src_end, tgt_end = mappings_sorted[end_idx]
                                range_labels.append(f"[{src_end}:{src_start}]→[{tgt_end}:{tgt_start}]")
                        
                        # Combine ranges
                        if len(range_labels) <= 3:
                            wire_label = ", ".join(range_labels)
                        else:
                            # Too many - show first few
                            wire_label = ", ".join(range_labels[:2]) + f", ... (+{len(range_labels)-2})"
                else:
                    wire_label = 'wire'
                
                G.add_edge(src, tgt, edge_type='wire', expression=wire_label)
        
        return G
    
    def visualize_bundled(self, signal_name, bit_index, graph, output_file='trace_bundled.svg'):
        """Visualize bundled graph"""
        if len(graph.nodes()) == 0:
            print("No trace found")
            return
        
        num_nodes = len(graph.nodes())
        num_edges = len(graph.edges())
        fig_width = max(60, num_nodes * 4.0)
        fig_height = max(40, num_nodes * 2.5)
        
        plt.figure(figsize=(fig_width, fig_height))
        
        target_node = f"{signal_name}[{bit_index}]"
        
        # Hierarchical layout
        try:
            node_layers = {}
            sources = [n for n in graph.nodes() if graph.in_degree(n) == 0]
            
            for node in graph.nodes():
                node_layers[node] = -1
            
            for source in sources:
                node_layers[source] = 0
            
            for node in nx.topological_sort(graph):
                if node_layers[node] == -1:
                    pred_layers = [node_layers[pred] for pred in graph.predecessors(node) 
                                  if node_layers[pred] != -1]
                    if pred_layers:
                        node_layers[node] = max(pred_layers) + 1
                    else:
                        node_layers[node] = 0
            
            if target_node in node_layers:
                max_layer = max(node_layers.values())
                node_layers[target_node] = max_layer + 1
            
            layers = defaultdict(list)
            for node, layer in node_layers.items():
                layers[layer].append(node)
            
            max_nodes_in_layer = max(len(nodes) for nodes in layers.values())
            vertical_spacing = max(12.0, max_nodes_in_layer * 1.5)
            horizontal_spacing = 20.0
            
            sorted_layers = sorted(layers.keys())
            layer_order = {layer_idx: sorted(nodes) for layer_idx, nodes in layers.items()}
            
            for layer_idx in sorted_layers:
                layer_order[layer_idx] = sorted(layers[layer_idx], 
                                               key=lambda n: -graph.out_degree(n))
            
            for iteration in range(10):
                for i in range(1, len(sorted_layers)):
                    layer_idx = sorted_layers[i]
                    nodes = layer_order[layer_idx]
                    
                    barycenters = {}
                    for node in nodes:
                        predecessors = list(graph.predecessors(node))
                        if predecessors:
                            pred_positions = []
                            for pred in predecessors:
                                for prev_layer_idx in sorted_layers[:i]:
                                    if pred in layer_order[prev_layer_idx]:
                                        pred_pos = layer_order[prev_layer_idx].index(pred)
                                        pred_positions.append(pred_pos)
                            if pred_positions:
                                barycenters[node] = sum(pred_positions) / len(pred_positions)
                            else:
                                barycenters[node] = layer_order[layer_idx].index(node)
                        else:
                            barycenters[node] = layer_order[layer_idx].index(node)
                    
                    layer_order[layer_idx] = sorted(nodes, key=lambda n: barycenters.get(n, 0))
                
                for i in range(len(sorted_layers) - 2, -1, -1):
                    layer_idx = sorted_layers[i]
                    nodes = layer_order[layer_idx]
                    
                    barycenters = {}
                    for node in nodes:
                        successors = list(graph.successors(node))
                        if successors:
                            succ_positions = []
                            for succ in successors:
                                for next_layer_idx in sorted_layers[i+1:]:
                                    if succ in layer_order[next_layer_idx]:
                                        succ_pos = layer_order[next_layer_idx].index(succ)
                                        succ_positions.append(succ_pos)
                            if succ_positions:
                                barycenters[node] = sum(succ_positions) / len(succ_positions)
                            else:
                                barycenters[node] = layer_order[layer_idx].index(node)
                        else:
                            barycenters[node] = layer_order[layer_idx].index(node)
                    
                    layer_order[layer_idx] = sorted(nodes, key=lambda n: barycenters.get(n, 0))
            
            pos = {}
            for layer_idx in sorted_layers:
                nodes = layer_order[layer_idx]
                x = layer_idx * horizontal_spacing
                num_nodes = len(nodes)
                
                if num_nodes == 1:
                    positions = [0]
                else:
                    total_height = (num_nodes - 1) * vertical_spacing
                    positions = [i * vertical_spacing - total_height / 2 for i in range(num_nodes)]
                
                for i, node in enumerate(nodes):
                    pos[node] = (x, positions[i])
        except Exception as e:
            print(f"Warning: Layout failed ({e})")
            pos = nx.spring_layout(graph, k=3, iterations=100)
        
        # Draw nodes
        for node_type, color, shape, size in [('external_input', 'lightgreen', 'o', 3500),
                                               ('module_input', 'lightblue', 's', 3000),
                                               ('module_output', 'lightyellow', 's', 3000)]:
            nodes_of_type = [n for n in graph.nodes() 
                           if graph.nodes[n]['node_type'] == node_type and n != target_node]
            if nodes_of_type:
                nx.draw_networkx_nodes(graph, pos, 
                                      nodelist=nodes_of_type,
                                      node_color=color,
                                      node_shape=shape,
                                      node_size=size,
                                      alpha=0.9)
        
        if target_node in graph.nodes():
            nx.draw_networkx_nodes(graph, pos,
                                  nodelist=[target_node],
                                  node_color='red',
                                  node_shape='*',
                                  node_size=5000,
                                  alpha=1.0,
                                  edgecolors='darkred',
                                  linewidths=3)
        
        # Draw edges
        wire_edges = [(u, v) for u, v, d in graph.edges(data=True) if d.get('edge_type') == 'wire']
        module_edges = [(u, v) for u, v, d in graph.edges(data=True) if d.get('edge_type') == 'module']
        
        if wire_edges:
            nx.draw_networkx_edges(graph, pos, edgelist=wire_edges,
                                 edge_color='blue', arrows=True, arrowsize=25,
                                 width=2.5, alpha=0.8, connectionstyle='arc3,rad=0')
        
        if module_edges:
            nx.draw_networkx_edges(graph, pos, edgelist=module_edges,
                                 edge_color='darkorange', arrows=True, arrowsize=20,
                                 width=2, alpha=0.7, connectionstyle='arc3,rad=0')
        
        # Draw node labels with clearer format
        labels = {}
        for node in graph.nodes():
            node_data = graph.nodes[node]
            if node == target_node:
                labels[node] = f"TARGET\nout_flat[{bit_index}]"
            elif node_data['node_type'] == 'module_input':
                module = node_data['module']
                # Extract bit range
                if ':' in node:
                    bit_range = re.search(r'\[([^\]]+)\]', node).group(1)
                    labels[node] = f"[{module}] in\n[{bit_range}]"
                else:
                    bit = re.search(r'\[(\d+)\]', node).group(1)
                    labels[node] = f"[{module}] in\n[{bit}]"
            elif node_data['node_type'] == 'module_output':
                module = node_data['module']
                if ':' in node:
                    bit_range = re.search(r'\[([^\]]+)\]', node).group(1)
                    labels[node] = f"[{module}] out\n[{bit_range}]"
                else:
                    bit = re.search(r'\[(\d+)\]', node).group(1)
                    labels[node] = f"[{module}] out\n[{bit}]"
            else:
                if ':' in node:
                    bit_range = re.search(r'\[([^\]]+)\]', node).group(1)
                    labels[node] = f"INPUT\n[{bit_range}]"
                else:
                    bit = re.search(r'\[(\d+)\]', node).group(1)
                    labels[node] = f"INPUT\n[{bit}]"
        
        nx.draw_networkx_labels(graph, pos, labels, font_size=10, verticalalignment='center',
                               bbox=dict(boxstyle='round,pad=0.5', facecolor='white', alpha=0.98,
                                        edgecolor='black', linewidth=1.5))
        
        if target_node in graph.nodes():
            nx.draw_networkx_labels(graph, pos, {target_node: labels[target_node]}, 
                                   font_size=14, font_weight='bold',
                                   font_color='darkred', verticalalignment='center',
                                   bbox=dict(boxstyle='round,pad=0.6', facecolor='#ffcccc', 
                                           alpha=0.98, edgecolor='darkred', linewidth=2.5))
        
        # Draw edge labels (expressions and wire mappings)
        module_edge_labels = {}
        wire_edge_labels = {}
        
        for u, v, d in graph.edges(data=True):
            expr = d.get('expression', '')
            if expr:
                if d.get('edge_type') == 'module':
                    # Truncate if too long
                    if len(expr) > 50:
                        expr = expr[:47] + "..."
                    module_edge_labels[(u, v)] = expr
                elif d.get('edge_type') == 'wire' and expr:
                    wire_edge_labels[(u, v)] = expr
        
        # Draw module expressions (prominent) with offset to avoid overlap
        if module_edge_labels:
            nx.draw_networkx_edge_labels(graph, pos, module_edge_labels, 
                                         font_size=9, font_color='darkgreen',
                                         font_weight='bold',
                                         label_pos=0.6,  # Position at 60% along edge
                                         bbox=dict(boxstyle='round,pad=0.5', 
                                                 facecolor='lightyellow', alpha=0.95,
                                                 edgecolor='orange', linewidth=2))
        
        # Draw wire labels (positioned differently to avoid overlap)
        if wire_edge_labels:
            nx.draw_networkx_edge_labels(graph, pos, wire_edge_labels, 
                                         font_size=8, font_color='darkblue',
                                         label_pos=0.3,  # Position at 30% along edge
                                         bbox=dict(boxstyle='round,pad=0.3', 
                                                 facecolor='lightcyan', alpha=0.9,
                                                 edgecolor='blue', linewidth=1))
        
        # Legend
        from matplotlib.lines import Line2D
        num_inputs = len([n for n in graph.nodes() 
                         if graph.nodes[n]['node_type'] == 'external_input'])
        modules = set([graph.nodes[n]['module'] for n in graph.nodes() 
                      if graph.nodes[n]['module'] != 'N/A'])
        
        legend_elements = [
            mpatches.Patch(color='lightgreen', label='External Input'),
            mpatches.Patch(color='lightblue', label='Module Input'),
            mpatches.Patch(color='lightyellow', label='Module Output'),
            Line2D([0], [0], marker='*', color='w', markerfacecolor='red', 
                   markersize=15, label='Target', markeredgecolor='darkred', markeredgewidth=2),
            Line2D([0], [0], color='blue', linewidth=2.5, label='Wire'),
            Line2D([0], [0], color='darkorange', linewidth=2, label='Logic (labeled)')
        ]
        plt.legend(handles=legend_elements, loc='upper left', fontsize=11)
        
        plt.title(f'Bundled Bit Trace: {signal_name}[{bit_index}]\n'
                 f'{num_inputs} input bundles → {len(modules)} modules (showing logic)',
                 fontsize=15, fontweight='bold')
        plt.grid(True, alpha=0.3, linestyle=':', linewidth=0.5)
        plt.axis('on')
        plt.xlabel('Processing Stage', fontsize=12)
        plt.ylabel('Bit Bundles', fontsize=12)
        plt.tight_layout()
        
        if output_file.endswith('.svg'):
            plt.savefig(output_file, format='svg', bbox_inches='tight')
        else:
            plt.savefig(output_file, dpi=150, bbox_inches='tight')
        
        print(f"Bundled trace saved to {output_file}")
        plt.close()


def main():
    parser = argparse.ArgumentParser(description='Trace bit with bundled ranges and logic')
    parser.add_argument('--bit', type=int, required=True, help='Output bit to trace')
    parser.add_argument('--top', default='top.sv', help='Top-level file')
    parser.add_argument('--modules', default='/Users/frank.jin/Desktop/module-fuzz/test_libraries/comprehensive_tests',
                       help='Module directory')
    parser.add_argument('--output', default='trace_bundled.svg', help='Output file')
    
    args = parser.parse_args()
    
    print(f"Analyzing and bundling bits...")
    tracer = BundledBitTracer(args.top, args.modules)
    
    print(f"Tracing out_flat[{args.bit}] with bundling...")
    graph, visited = tracer.trace_and_bundle('out_flat', args.bit)
    
    print(f"Traced {len(visited)} individual bits")
    print(f"Bundled into {len(graph.nodes())} nodes and {len(graph.edges())} connections")
    
    num_inputs = len([n for n in graph.nodes() 
                     if graph.nodes[n]['node_type'] == 'external_input'])
    print(f"Final: {num_inputs} input bundles")
    
    tracer.visualize_bundled('out_flat', args.bit, graph, args.output)
    print(f"\nDone! Open {args.output}")

if __name__ == '__main__':
    main()

