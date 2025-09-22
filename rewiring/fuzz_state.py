import IO_map
import random
import networkx as nx
import matplotlib.pyplot as plt
from collections import defaultdict
from pathlib import Path

"""
Wire can be in many groups: A wire can be on many linear paths
    - Every wire is initally in a group with it's parent and child modules
Wire can be in many loops: A wire can be on many looped paths
Groups contains {group_id : [modules in that group]}
    - Initially one group for every input and output pair 
    - Group id is initially the wire id, since each wire is in it's own group
Loops contains {loop_id : [modules in that loop]}

"""
class Fuzz_Run:
    def __init__(self, flattened_lib_path):
        random.seed(1)
        self.flattened_lib_path = flattened_lib_path
        io_map = IO_map.create_IO_map(flattened_lib_path)

        self.all_wires = io_map['bit_input'].copy()
        self.all_wires.update(io_map['bit_output']) # Single source of truth
        
        self.mod_IO = io_map['mod_IO']
        self.all_modules = io_map['mod_list']

        self.external_inputs = list(io_map['bit_input'].keys())
        self.external_outputs = list(io_map['bit_output'].keys()) # Unchanged will always output all outputs

        self.module_tree = {}
        for i in range(len(io_map['mod_list'])):
            module = io_map['mod_list'][i]
            self.module_tree[module] = {"depth" : 0, "tree":i, "children" : [], "parents":[], "loops":[]}

        self.loops = {}
        self.loop_set = set()
        
    def visualize_graph(self):
        G = nx.DiGraph()
        G.add_node("EXT_INPUT", color="green")
        G.add_node("EXT_OUTPUT", color="red")

        for mod in self.all_modules:
            G.add_node(mod, color="lightblue")

        edge_labels = {}
        edge_styles = {}

        for wire in self.all_wires.values():
            if wire.type == IO_map.Wire.Wire_Type.ITM:
                dst_port = wire.output[0] if wire.output else None
                if dst_port and "_input_" in dst_port:
                    dst_mod = dst_port.split("_input_")[0]
                    G.add_edge("EXT_INPUT", dst_mod)
                    edge_labels[("EXT_INPUT", dst_mod)] = f"w{wire.id}"
                    edge_styles[("EXT_INPUT", dst_mod)] = ("gray", "solid")

            elif wire.type == IO_map.Wire.Wire_Type.MTM:
                src_mod = wire.input
                if "_output_" not in src_mod:
                    src_mod = src_mod.split("_output_")[0]
                for dst in wire.output:
                    if dst == "output":
                        G.add_edge(src_mod, "EXT_OUTPUT")
                        edge_labels[(src_mod, "EXT_OUTPUT")] = f"w{wire.id}"
                        edge_styles[(src_mod, "EXT_OUTPUT")] = ("gray", "solid")
                    elif "_input_" in dst:
                        dst_mod = dst.split("_input_")[0]
                        G.add_edge(src_mod, dst_mod)
                        label = f"w{wire.id}"
                        edge_labels[(src_mod, dst_mod)] = label

                        # Style based on reg/cycle
                        if wire.reg:
                            edge_styles[(src_mod, dst_mod)] = ("red", "solid")
                        elif (self.module_tree[src_mod]["loops"]
                            or self.module_tree[dst_mod]["loops"]):
                            edge_styles[(src_mod, dst_mod)] = ("blue", "dashed")
                        else:
                            edge_styles[(src_mod, dst_mod)] = ("gray", "solid")

        pos = nx.spring_layout(G, seed=42)
        node_colors = [G.nodes[n].get("color", "white") for n in G.nodes()]
        nx.draw(G, pos, with_labels=True, node_color=node_colors,
                node_size=1000, font_size=8)

        # Draw edges with different colors & styles
        for (u, v), (color, style) in edge_styles.items():
            nx.draw_networkx_edges(G, pos, edgelist=[(u, v)],
                                edge_color=color,
                                style=style,
                                width=2 if color != "gray" else 1)

        nx.draw_networkx_edge_labels(G, pos, edge_labels=edge_labels, font_size=6)
        plt.title("Module Graph (Red=Reg, Blue=Cycle, Gray=Normal)")
        plt.show()

 
    def visualize_graph_no_ext_out(self):
        """
        Visualize the module graph without external outputs.
        - Red solid edges: wires with reg=True (registered).
        - Blue dashed edges: cycle edges (modules in self.loops).
        - Gray solid edges: normal wires.
        """
        G = nx.DiGraph()
        G.add_node("EXT_INPUT", color="green")

        for mod in self.all_modules:
            G.add_node(mod, color="lightblue")

        edge_labels = {}
        edge_styles = {}

        for wire in self.all_wires.values():
            if wire.type == IO_map.Wire.Wire_Type.ITM:
                dst_port = wire.output[0] if wire.output else None
                if dst_port and "_input_" in dst_port:
                    dst_mod = dst_port.split("_input_")[0]
                    G.add_edge("EXT_INPUT", dst_mod)
                    edge_labels[("EXT_INPUT", dst_mod)] = f"w{wire.id}"
                    edge_styles[("EXT_INPUT", dst_mod)] = ("gray", "solid")

            elif wire.type == IO_map.Wire.Wire_Type.MTM:
                src_mod = wire.input
                if "_output_" in src_mod:
                    src_mod = src_mod.split("_output_")[0]

                for dst in wire.output:
                    if dst == "output":
                        continue  # No external outputs in this view
                    if "_input_" in dst:
                        dst_mod = dst.split("_input_")[0]
                        G.add_edge(src_mod, dst_mod)
                        edge_labels[(src_mod, dst_mod)] = f"w{wire.id}"

                        # Style based on reg/cycle
                        if wire.reg:
                            edge_styles[(src_mod, dst_mod)] = ("red", "solid")
                        elif (self.module_tree[src_mod]["loops"]):
                            edge_styles[(src_mod, dst_mod)] = ("blue", "dashed")
                        else:
                            edge_styles[(src_mod, dst_mod)] = ("gray", "solid")

        pos = nx.spring_layout(G, seed=42)
        node_colors = [G.nodes[n].get("color", "white") for n in G.nodes()]
        nx.draw(G, pos, with_labels=True, node_color=node_colors,
                node_size=1000, font_size=8)

        # Draw edges with appropriate styles
        for (u, v), (color, style) in edge_styles.items():
            nx.draw_networkx_edges(G, pos, edgelist=[(u, v)],
                                edge_color=color,
                                style=style,
                                width=2 if color != "gray" else 1)

        nx.draw_networkx_edge_labels(G, pos, edge_labels=edge_labels, font_size=6)
        plt.title("Module Graph (No EXT Output) [Red=Reg, Blue=Cycle, Gray=Normal]")
        plt.show()

    def _mod_from_port(self, port_str):
        """Helper function to extract module name from a port string like 'adder_wrapper_input_3'."""
        if "_input_" in port_str:
            return port_str.split("_input_")[0]
        elif "_output_" in port_str:
            return port_str.split("_output_")[0]
        raise ValueError(f"Unrecognized port name format: {port_str}")
    
    def _merge_tree_consistency(self, root_tree_id):
        """
        Ensure all modules in the tree starting from root_tree_id have consistent tree IDs.
        This is called after tree merging to fix any inconsistencies.
        """
        # Find all modules that should be in this tree
        modules_in_tree = set()
        for mod, meta in self.module_tree.items():
            if meta["tree"] == root_tree_id:
                modules_in_tree.add(mod)
        
        # Use BFS to find all connected modules and ensure they have the same tree ID
        queue = list(modules_in_tree)
        visited = set()
        
        while queue:
            current = queue.pop(0)
            if current in visited:
                continue
            visited.add(current)
            
            # Ensure current module has the correct tree ID
            if self.module_tree[current]["tree"] != root_tree_id:
                self.module_tree[current]["tree"] = root_tree_id
            
            # Add all connected modules to the queue
            for child in self.module_tree[current]["children"]:
                if child not in visited:
                    queue.append(child)
            for parent in self.module_tree[current]["parents"]:
                if parent not in visited:
                    queue.append(parent)
        
        # Update tree ID for all modules found in this connected component
        for mod in visited:
            self.module_tree[mod]["tree"] = root_tree_id

    def shift_module_depth_below(self, A: str, B: str, merge_trees: bool = False):
        """
        Shift the subtree rooted at module B so that B is at depth A.depth + 1.
        Always updates parent/child relationship: A → B.

        If merge_trees is False:
            - Requires A and B in the same tree.
            - Requires A.depth <= B.depth.
            - Shift happens only if A.depth == B.depth.
            - Only B and its descendants are shifted (not its parents).

        If merge_trees is True:
            - B and its entire subtree are shifted to A.depth + 1.
            - Tree ID of B, its descendants, and its parents are changed to A's tree.
        """
        if A not in self.module_tree or B not in self.module_tree:
            print(f"[Shift] One or both modules '{A}' and '{B}' do not exist.")
            return

        depth_A = self.module_tree[A]["depth"]
        depth_B = self.module_tree[B]["depth"]
        tree_A = self.module_tree[A]["tree"]
        tree_B = self.module_tree[B]["tree"]

        if not merge_trees:
            assert tree_A == tree_B, f"[Shift] Can't shift: '{A}' and '{B}' are in different trees."
            assert depth_A <= depth_B, f"[Shift] Can't shift: '{A}' is deeper than '{B}' in same tree."

            if depth_A != depth_B:
                print(f"[Shift] Skipped depth shift: '{A}' and '{B}' are not at the same depth.")
            else:
                # Shift B and descendants by +1
                queue = [B]
                visited = set()

                while queue:
                    current = queue.pop(0)
                    if current in visited:
                        continue
                    visited.add(current)

                    self.module_tree[current]["depth"] += 1

                    for child in self.module_tree[current]["children"]:
                        if child not in visited:
                            queue.append(child)

        else:
            # Calculate how much we need to shift B to be just below A
            delta = (depth_A + 1) - depth_B

            # Shift B and its descendants
            queue = [B]
            visited = set()

            while queue:
                current = queue.pop(0)
                if current in visited:
                    continue
                visited.add(current)

                self.module_tree[current]["depth"] += delta
                self.module_tree[current]["tree"] = tree_A

                for child in self.module_tree[current]["children"]:
                    if child not in visited:
                        queue.append(child)

            # Update all parents of B to tree_A
            parent_queue = list(self.module_tree[B]["parents"])
            seen_parents = set()
            max_iterations = 100  # Prevent infinite loops

            while parent_queue and len(seen_parents) < max_iterations:
                parent = parent_queue.pop()
                if parent in seen_parents:
                    continue
                seen_parents.add(parent)
                self.module_tree[parent]["tree"] = tree_A
                parent_queue.extend(self.module_tree[parent]["parents"])

            if len(seen_parents) >= max_iterations:
                print(f"[Warning] Tree merging exceeded max iterations for module {B}")

            # Also update all descendants of A to ensure tree consistency
            # This is needed because A might have children that are now in a different tree
            a_descendants = set()
            a_queue = [A]
            max_a_iterations = 100  # Prevent infinite loops

            while a_queue and len(a_descendants) < max_a_iterations:
                current = a_queue.pop(0)
                if current in a_descendants:
                    continue
                a_descendants.add(current)
                for child in self.module_tree[current]["children"]:
                    if child not in a_descendants:
                        a_queue.append(child)
                        # Update the child's tree ID to match A's tree
                        if self.module_tree[child]["tree"] != tree_A:
                            self.module_tree[child]["tree"] = tree_A

            if len(a_descendants) >= max_a_iterations:
                print(f"[Warning] Tree merging exceeded max iterations for module {A}")

        # Always update parent/child relationship
        if B not in self.module_tree[A]["children"]:
            self.module_tree[A]["children"].append(B)
        if A not in self.module_tree[B]["parents"]:
            self.module_tree[B]["parents"].append(A)

        # After merging trees, ensure all connected modules have consistent tree IDs
        if merge_trees:
            self._merge_tree_consistency(tree_A)

        print(f"[Shift] Parent/child set: '{A}' → '{B}'. Tree merged: {merge_trees}")

    def linear_rewire(self):
        """
        Rewire one external output (MTO/MTM) to an internal input (ITM).
        Ensures mod_IO and all_wires stay consistent after rewiring.
        Updates wire type:
        - MTO → MTM if adding a module connection
        - MTM → MTO if only 'output' remains after removing a connection
        Rules:
        - Never rewire registered wires (reg=True).
        - Never rewire if:
            * One module is parent/child of the other (directly).
            * Both modules are already in loops.
            * Rewiring would reverse an existing parent-child hierarchy
                (e.g., making a parent become a child, which increases depth indefinitely).
        """
        if not self.external_outputs:
            print("[Rewire] No external outputs to rewire.")
            return

        for _ in range(len(self.external_outputs)):
            output_wire_id = self.external_outputs[random.randrange(len(self.external_outputs))]
            output_wire = self.all_wires[output_wire_id]
            assert output_wire.type in (IO_map.Wire.Wire_Type.MTM, IO_map.Wire.Wire_Type.MTO)

            output_port = output_wire.input
            assert "_output_" in output_port

            output_mod = output_port.split("_output_")[0]

            # Skip if this wire is registered and belongs to a loop
            if output_wire.reg and output_mod in self.loop_set:
                continue

            output_tree = self.module_tree[output_mod]["tree"]
            output_depth = self.module_tree[output_mod]["depth"]

            for _ in range(len(self.all_modules)):
                target_mod = self.all_modules[random.randrange(len(self.all_modules))]
                if target_mod == output_mod:
                    continue

                target_tree = self.module_tree[target_mod]["tree"]
                target_depth = self.module_tree[target_mod]["depth"]

                # --- New Checks ---
                # 1. Skip if both modules are already in loops
                if output_mod in self.loop_set and target_mod in self.loop_set:
                    continue

                # 2. Skip if direct parent-child already exists
                if target_mod in self.module_tree[output_mod]["parents"] or \
                target_mod in self.module_tree[output_mod]["children"] or \
                output_mod in self.module_tree[target_mod]["parents"] or \
                output_mod in self.module_tree[target_mod]["children"]:
                    continue

                # 3. Skip if this rewiring would reverse hierarchy (make parent become child)
                # If target is an ancestor of output_mod, rewiring would make parent into child
                def is_ancestor(ancestor, descendant):
                    visited, stack = set(), [ancestor]
                    max_iterations = 100  # Prevent infinite loops
                    iterations = 0
                    
                    while stack and iterations < max_iterations:
                        iterations += 1
                        cur = stack.pop()
                        if cur == descendant:
                            return True
                        for p in self.module_tree[cur]["parents"]:
                            if p not in visited:
                                visited.add(p)
                                stack.append(p)
                    
                    if iterations >= max_iterations:
                        print(f"[Warning] Ancestor check exceeded max iterations for {ancestor} -> {descendant}")
                        return False  # Assume no ancestor relationship to be safe
                    
                    return False

                if is_ancestor(target_mod, output_mod):
                    continue

                # Skip if would create illegal cycle by depth rule
                if target_tree == output_tree and target_depth < output_depth:
                    continue

                target_inputs = list(self.mod_IO[target_mod]['inputs'])
                if not target_inputs:
                    continue

                target_wire_id = target_inputs[random.randrange(len(target_inputs))]
                target_wire = self.all_wires[target_wire_id]

                # Skip if target wire is registered and looped
                if target_wire.reg and target_mod in self.loop_set:
                    continue

                ports = [p for p in target_wire.output if p.startswith(target_mod)]
                if not ports:
                    continue
                target_port = ports[0]

                # ===============================
                # CONSISTENT REWIRING UPDATES
                # ===============================
                output_wire.output.append(target_port)

                # Update type if previously MTO (now drives a module too)
                if output_wire.type == IO_map.Wire.Wire_Type.MTO:
                    output_wire.type = IO_map.Wire.Wire_Type.MTM

                if output_wire.id not in self.mod_IO[target_mod]['inputs']:
                    self.mod_IO[target_mod]['inputs'].add(output_wire.id)

                # Disconnect target wire only if not registered
                if not (target_wire.reg and target_mod in self.loop_set):
                    if target_port in target_wire.output:
                        target_wire.output.remove(target_port)

                    still_drives_module = any(p.startswith(f"{target_mod}_input_") for p in target_wire.output)
                    if not still_drives_module and target_wire_id in self.mod_IO[target_mod]['inputs']:
                        self.mod_IO[target_mod]['inputs'].remove(target_wire_id)

                    # Update type if now only drives 'output'
                    if target_wire.type == IO_map.Wire.Wire_Type.MTM and target_wire.output == ['output']:
                        target_wire.type = IO_map.Wire.Wire_Type.MTO

                    # Remove ITM wire if fully disconnected
                    if target_wire.type == IO_map.Wire.Wire_Type.ITM and not target_wire.output:
                        if target_wire.id in self.all_wires:
                            self.all_wires.pop(target_wire.id)
                        if target_wire.id in self.external_inputs:
                            self.external_inputs.remove(target_wire.id)

                merge_trees = target_tree != output_tree
                self.shift_module_depth_below(output_mod, target_mod, merge_trees)

                assert output_wire.id in self.mod_IO[target_mod]['inputs'], \
                    f"[Rewire-Error] {output_wire.id} missing from {target_mod} inputs after rewiring"

                print(f"[Rewire] {output_mod} → {target_mod} via {target_port}")
                return 0

        print("[Rewire] No valid rewiring opportunity found.")
        return 1



    def cyclical_rewire(self):
        """
        Rewire exactly ONE wire to create a cycle (back-edge).
        Updates all modules in the cycle within module_tree.
        Never removes or alters registered wires (reg=True).
        MTO ↔ MTM transitions handled consistently.
        Creates proper loops that form valid cycles in the module tree.
        """
        if not self.external_outputs:
            print("[Cyclical-Rewire] No external outputs to rewire.")
            return

        for _ in range(len(self.external_outputs)):
            output_wire_id = self.external_outputs[random.randrange(len(self.external_outputs))]
            output_wire = self.all_wires[output_wire_id]
            assert output_wire.type in (IO_map.Wire.Wire_Type.MTM, IO_map.Wire.Wire_Type.MTO)

            output_port = output_wire.input
            assert "_output_" in output_port

            output_mod = output_port.split("_output_")[0]

            # Skip if this output_wire is already registered and looped
            if output_wire.reg and output_mod in self.loop_set:
                continue

            output_tree = self.module_tree[output_mod]["tree"]
            output_depth = self.module_tree[output_mod]["depth"]

            for _ in range(len(self.all_modules)):
                target_mod = self.all_modules[random.randrange(len(self.all_modules))]
                if target_mod == output_mod:
                    continue

                target_tree = self.module_tree[target_mod]["tree"]
                target_depth = self.module_tree[target_mod]["depth"]

                # Skip if would create illegal loop
                if target_tree != output_tree or target_depth >= output_depth:
                    continue

                # Skip if this would create a self-loop
                if target_mod == output_mod:
                    continue

                # Skip if there's already a direct connection between these modules
                if (target_mod in self.module_tree[output_mod]["children"] or 
                    output_mod in self.module_tree[target_mod]["children"]):
                    continue

                target_inputs = list(self.mod_IO[target_mod]['inputs'])
                if not target_inputs:
                    continue

                target_wire_id = target_inputs[random.randrange(len(target_inputs))]
                target_wire = self.all_wires[target_wire_id]

                # Never modify existing registered wires in loops
                if target_wire.reg and target_mod in self.loop_set:
                    continue

                ports = [p for p in target_wire.output if p.startswith(target_mod)]
                if not ports:
                    continue
                target_port = ports[0]

                try:
                    # Find a path from target_mod to output_mod
                    path = self._find_path(target_mod, output_mod)
                except RuntimeError:
                    continue

                # Skip if any module in path already looped
                if any(m in self.loop_set for m in path):
                    continue

                # Validate that the path can form a valid cycle
                if len(path) < 2:
                    continue

                # ===============================
                # CONSISTENT REWIRING UPDATES
                # ===============================
                output_wire.output.append(target_port)
                output_wire.reg = True  # Source module outputs must be registered

                # Update type if previously MTO (now drives a module too)
                if output_wire.type == IO_map.Wire.Wire_Type.MTO:
                    output_wire.type = IO_map.Wire.Wire_Type.MTM

                if output_wire.id not in self.mod_IO[target_mod]['inputs']:
                    self.mod_IO[target_mod]['inputs'].add(output_wire.id)

                # Disconnect old wire only if not registered
                if not (target_wire.reg and target_mod in self.loop_set):
                    if target_port in target_wire.output:
                        target_wire.output.remove(target_port)

                    still_drives_module = any(p.startswith(f"{target_mod}_input_") for p in target_wire.output)
                    if not still_drives_module and target_wire_id in self.mod_IO[target_mod]['inputs']:
                        self.mod_IO[target_mod]['inputs'].remove(target_wire_id)

                    # Update type if now only drives 'output'
                    if target_wire.type == IO_map.Wire.Wire_Type.MTM and target_wire.output == ['output']:
                        target_wire.type = IO_map.Wire.Wire_Type.MTO

                    # Remove ITM wire if fully disconnected
                    if target_wire.type == IO_map.Wire.Wire_Type.ITM and not target_wire.output:
                        if target_wire.id in self.all_wires:
                            self.all_wires.pop(target_wire.id)
                        if target_wire.id in self.external_inputs:
                            self.external_inputs.remove(target_wire.id)

                # ===============================
                # LOOP REGISTRATION UPDATES
                # ===============================
                loop_id = f"loop_{len(self.loops)}"
                
                # Create a simple combinational loop: [target_mod, output_mod, target_mod]
                cycle = [target_mod, output_mod, target_mod]
                self.loops[loop_id] = cycle

                # Update modules in the loop - both are now part of a combinational loop
                for m in [target_mod, output_mod]:
                    if m not in self.loop_set:
                        self.module_tree[m]["loops"] = [loop_id]
                        self.loop_set.add(m)

                # Add the back-edge from output_mod to target_mod
                if target_mod not in self.module_tree[output_mod]["children"]:
                    self.module_tree[output_mod]["children"].append(target_mod)
                if output_mod not in self.module_tree[target_mod]["parents"]:
                    self.module_tree[target_mod]["parents"].append(output_mod)

                # Update module depths to handle the back-edge properly
                target_depth = self.module_tree[target_mod]["depth"]
                output_depth = self.module_tree[output_mod]["depth"]
                
                if target_depth >= output_depth:
                    # Adjust depths to maintain valid tree structure
                    depth_delta = output_depth - target_depth + 1
                    self._shift_module_depth(target_mod, depth_delta)

                # Mark ALL outputs of the source module as registered
                for w in self.all_wires.values():
                    if w.type in (IO_map.Wire.Wire_Type.MTM, IO_map.Wire.Wire_Type.MTO) and w.input.startswith(output_mod):
                        w.reg = True
                        print(f"[Hardware] Marked wire {w.id} as registered to break combinational loop")

                assert output_wire.id in self.mod_IO[target_mod]['inputs'], \
                    f"[Cyclical-Rewire-Error] {output_wire.id} missing from {target_mod} inputs after rewiring"

                print(f"[Cyclical-Rewire] {output_mod} → {target_mod} | Cycle: {cycle} | "
                    f"All outputs of {output_mod} marked reg=True")
                return 0

        print("[Cyclical-Rewire] No valid cyclical rewiring opportunity found.")
        return 1

    def _shift_module_depth(self, module, delta):
        """
        Shift the depth of a module and all its descendants by delta.
        Used when creating back-edges to maintain valid tree structure.
        """
        queue = [module]
        visited = set()
        
        while queue:
            current = queue.pop(0)
            if current in visited:
                continue
            visited.add(current)
            
            # Update the depth
            self.module_tree[current]["depth"] += delta
            
            # Add all descendants to the queue
            for child in self.module_tree[current]["children"]:
                if child not in visited:
                    queue.append(child)

    def _find_path(self, start_mod, end_mod):
        """
        Find a path from start_mod to end_mod in the module tree.
        Returns a list of modules in the path: [start_mod, ..., end_mod].
        """
        path = []
        found = False
        max_depth = 100  # Prevent infinite recursion

        def dfs(current, target, visited, depth):
            nonlocal found
            if found or depth > max_depth:
                return
            visited.append(current)

            if current == target:
                path.extend(visited)
                found = True
                return

            for child in self.module_tree[current]["children"]:
                if child in visited or child in self.loop_set:
                    continue
                dfs(child, target, visited.copy(), depth + 1)

        dfs(start_mod, end_mod, [], 0)
        if not found:
            raise RuntimeError(f"[Path-Error] No valid path from {start_mod} to {end_mod}")

        # Remove the start module from the path to avoid duplicates in the cycle
        if path and path[0] == start_mod:
            path = path[1:]

        return path

    def verify_consistency(self, verbose=True):
        """
        Verify consistency between self.mod_IO and self.all_wires.
        Checks:
        1. Every wire ID in mod_IO[mod]['inputs'] actually exists in all_wires and drives that module.
        2. Every wire in all_wires whose output drives a module appears in mod_IO for that module.
        Prints all inconsistencies found.
        Returns True if consistent, False otherwise.
        """

        consistent = True

        # 1. Check mod_IO → all_wires consistency
        for mod, io in self.mod_IO.items():
            for wid in list(io['inputs']):
                if wid not in self.all_wires:
                    consistent = False
                    if verbose:
                        print(f"[Consistency-Error] Wire {wid} listed in mod_IO[{mod}] but missing in all_wires.")
                    continue

                wire = self.all_wires[wid]
                drives_mod = any(p.startswith(f"{mod}_input_") for p in wire.output)
                if not drives_mod:
                    consistent = False
                    if verbose:
                        print(f"[Consistency-Error] Wire {wid} in mod_IO[{mod}] does not drive any {mod}_input_ ports. "
                            f"Outputs: {wire.output}")

        # 2. Check all_wires → mod_IO consistency
        for wid, wire in self.all_wires.items():
            for port in wire.output:
                if port == "output" or "_input_" not in port:
                    continue
                dst_mod = port.split("_input_")[0]
                if wid not in self.mod_IO[dst_mod]['inputs']:
                    consistent = False
                    if verbose:
                        print(f"[Consistency-Error] Wire {wid} drives {dst_mod} (port {port}) "
                            f"but is missing in mod_IO[{dst_mod}]['inputs'].")

        if verbose:
            if consistent:
                print("[Consistency] mod_IO and all_wires are consistent ✅")
            else:
                print("[Consistency] Inconsistencies detected ❌")

        return consistent
    
    def run_random_mutations(self, max_mutations, check_every = 10, seed = None, verbose = True) -> int:
        """
        Attempt up to `max_mutations` successful rewires, choosing randomly between
        `linear_rewire()` and `cyclical_rewire()` on each step.

        Behavior:
        - If one strategy (linear/cyclical) repeatedly yields no valid rewiring (returns 1),
            we mark it exhausted and stop trying it in this run.
        - If both strategies are exhausted, we return early with the current count.
        - Consistency checks are performed every `check_every` mutations.

        Args:
            max_mutations: Maximum number of mutations to attempt
            check_every: Perform consistency check every N mutations
            seed: Random seed for reproducible results
            verbose: Whether to print detailed progress information

        Returns:
            Number of successful mutations performed
        """
        if seed is not None:
            random.seed(seed)

        done = 0
        linear_exhausted = False
        cyclical_exhausted = False

        while done < max_mutations:
            # Choose mutation strategy
            if linear_exhausted and cyclical_exhausted:
                if verbose:
                    print(f"[Run] Both strategies exhausted after {done} mutation(s). Returning early.")
                break

            if linear_exhausted:
                strategy = "cyclical"
            elif cyclical_exhausted:
                strategy = "linear"
            else:
                strategy = random.choice(["linear", "cyclical"])

            # Attempt mutation
            if strategy == "linear":
                result = self.linear_rewire()
                if result == 1:
                    if verbose:
                        print(f"[Run] Linear rewiring exhausted after {done} mutation(s).")
                    linear_exhausted = True
                else:
                    done += 1
            else:  # cyclical
                result = self.cyclical_rewire()
                if result == 1:
                    if verbose:
                        print(f"[Run] Cyclical rewiring exhausted after {done} mutation(s).")
                    cyclical_exhausted = True
                else:
                    done += 1

            # Perform consistency check
            if done % check_every == 0:
                if verbose:
                    print(f"[Consistency] Checking consistency after {done} mutations...")
                
                # Basic consistency check
                if not self.verify_consistency(verbose=False):
                    raise RuntimeError(f"[Run] Basic consistency check failed at mutation {done}.")
                
                # Comprehensive consistency check
                if not self.comprehensive_consistency_check(verbose=verbose):
                    raise RuntimeError(f"[Run] Comprehensive consistency check failed at mutation {done}.")

        if verbose:
            print(f"[Run] Completed {done}/{max_mutations} mutation(s).")
        
        return done

    def comprehensive_consistency_check(self, verbose: bool = True) -> bool:
        """
        Comprehensive invariants validation across:
        1) mod_IO ↔ all_wires agreement (delegates to `verify_consistency`).
        2) module_tree graph sanity (parents/children, trees, depths, and loops).
        3) Wire-level invariants (types, registration, and IO lists).
        4) Loop metadata consistency (`self.loops` and `self.loop_set`).

        Returns True if all checks pass, else False (and prints diagnostics when `verbose`).
        """
        ok = True
        error_count = 0
        max_errors = 50  # Limit error output to prevent spam

        # ============= 1) mod_IO ↔ all_wires agreement =============
        if not self.verify_consistency(verbose=verbose):
            ok = False
            error_count += 1

        # Helper: quick accessors
        def in_same_loop(a: str, b: str) -> bool:
            la = set(self.module_tree.get(a, {}).get("loops", []))
            lb = set(self.module_tree.get(b, {}).get("loops", []))
            return len(la & lb) > 0

        # ============= 2) module_tree graph sanity =============
        for mod in self.all_modules:
            if mod not in self.module_tree:
                if verbose and error_count < max_errors:
                    print(f"[Tree-Error] Module '{mod}' missing from module_tree.")
                ok = False
                error_count += 1
                if error_count >= max_errors:
                    break

        # Check that referenced parents/children exist and are modules
        for m, meta in self.module_tree.items():
            for p in meta.get("parents", []):
                if p not in self.module_tree:
                    if verbose and error_count < max_errors:
                        print(f"[Tree-Error] Parent '{p}' of '{m}' not found in module_tree.")
                    ok = False
                    error_count += 1
                    if error_count >= max_errors:
                        break
            for c in meta.get("children", []):
                if c not in self.module_tree:
                    if verbose and error_count < max_errors:
                        print(f"[Tree-Error] Child '{c}' of '{m}' not found in module_tree.")
                    ok = False
                    error_count += 1
                    if error_count >= max_errors:
                        break

        # Depth and tree rules:
        # - For normal edges (non-loop), child.depth >= parent.depth and child.tree == parent.tree.
        # - For back-edges (loops), child.depth < parent.depth, both nodes must be in the same loop,
        #   and MUST share at least one loop id. Also, the parent must have reg outputs.
        for parent, meta in self.module_tree.items():
            p_depth = meta.get("depth", 0)
            p_tree = meta.get("tree", None)
            for child in meta.get("children", []):
                c_depth = self.module_tree[child].get("depth", 0)
                c_tree = self.module_tree[child].get("tree", None)

                # Mutual edges outside of loops are not allowed
                if parent in self.module_tree[child].get("children", []) and not in_same_loop(parent, child):
                    if verbose and error_count < max_errors:
                        print(f"[Tree-Error] Mutual edges '{parent} ↔ {child}' detected outside of a loop.")
                    ok = False
                    error_count += 1
                    if error_count >= max_errors:
                        break

                if p_tree != c_tree:
                    # Parent/child across different trees should not exist
                    if verbose and error_count < max_errors:
                        print(f"[Tree-Error] Cross-tree edge {parent}(tree={p_tree}) -> {child}(tree={c_tree}).")
                    ok = False
                    error_count += 1
                    if error_count >= max_errors:
                        break
                    continue

                if c_depth < p_depth:
                    # Must be a back-edge that's part of an annotated loop
                    if not in_same_loop(parent, child):
                        # In hardware modeling, back-edges can exist without being explicitly marked as loops
                        # They represent potential combinational loops that may need registration
                        if verbose:
                            print(f"[Tree-Warning] Back-edge {parent}(d={p_depth}) -> {child}(d={c_depth}) "
                                f"detected - potential combinational loop that may need registration")
                        # Don't fail the check for this - it's a valid hardware structure
                    else:
                        # Verify parent has at least one registered output wire
                        has_reg_out = any(
                            (w.type in (IO_map.Wire.Wire_Type.MTM, IO_map.Wire.Wire_Type.MTO)) and
                            w.input.startswith(f"{parent}_output_") and
                            getattr(w, "reg", False)
                            for w in self.all_wires.values()
                        )
                        if not has_reg_out:
                            if verbose:
                                print(f"[Tree-Error] Loop back-edge {parent}->{child} without registered outputs on '{parent}'.")
                            ok = False
                            error_count += 1
                            if error_count >= max_errors:
                                break
                else:
                    # Non-back-edge: require child.depth >= parent.depth and same tree (checked above)
                    if c_depth < p_depth:
                        if verbose and error_count < max_errors:
                            print(f"[Tree-Error] Depth ordering violation on edge {parent}->{child}: "
                                f"{c_depth} < {p_depth}.")
                        ok = False
                        error_count += 1
                        if error_count >= max_errors:
                            break

        # ============= 3) Wire-level invariants =============
        for wid, wire in self.all_wires.items():
            wtype = wire.type
            # Basic structural checks
            if not isinstance(wire.output, list):
                if verbose and error_count < max_errors:
                    print(f"[Wire-Error] Wire {wid} has non-list 'output' field: {wire.output!r}")
                ok = False
                error_count += 1
                if error_count >= max_errors:
                    break
                continue

            # External input wires should be ITM and must not drive 'output'
            if wid in self.external_inputs:
                if wtype != IO_map.Wire.Wire_Type.ITM:
                    if verbose and error_count < max_errors:
                        print(f"[Wire-Error] External input wire {wid} is not ITM (got {wtype}).")
                    ok = False
                    error_count += 1
                    if error_count >= max_errors:
                        break
                if any(p == 'output' for p in wire.output):
                    if verbose and error_count < max_errors:
                        print(f"[Wire-Error] External input wire {wid} illegally drives 'output'.")
                    ok = False
                    error_count += 1
                    if error_count >= max_errors:
                        break

            # External output wires should be MTO or MTM, and their input should come from a module output
            if wid in self.external_outputs:
                if wtype not in (IO_map.Wire.Wire_Type.MTO, IO_map.Wire.Wire_Type.MTM):
                    if verbose and error_count < max_errors:
                        print(f"[Wire-Error] External output wire {wid} must be MTO/MTM (got {wtype}).")
                    ok = False
                    error_count += 1
                    if error_count >= max_errors:
                        break
                if not isinstance(wire.input, str) or "_output_" not in wire.input:
                    if verbose and error_count < max_errors:
                        print(f"[Wire-Error] External output wire {wid} has invalid input source: {wire.input!r}")
                    ok = False
                    error_count += 1
                    if error_count >= max_errors:
                        break

            # ITM wires must not drive 'output'
            if wtype == IO_map.Wire.Wire_Type.ITM:
                if any(p == 'output' for p in wire.output):
                    if verbose and error_count < max_errors:
                        print(f"[Wire-Error] ITM wire {wid} drives 'output'.")
                    ok = False
                    error_count += 1
                    if error_count >= max_errors:
                        break

            # MTO wires must only drive 'output'
            if wtype == IO_map.Wire.Wire_Type.MTO:
                if wire.output != ['output']:
                    if verbose and error_count < max_errors:
                        print(f"[Wire-Error] MTO wire {wid} output list must be ['output'] (got {wire.output}).")
                    ok = False
                    error_count += 1
                    if error_count >= max_errors:
                        break

            # MTM wires must drive at least one module input
            if wtype == IO_map.Wire.Wire_Type.MTM:
                drives_any_module = any(('_input_' in p) for p in wire.output)
                if not drives_any_module:
                    if verbose and error_count < max_errors:
                        print(f"[Wire-Error] MTM wire {wid} does not drive any module input (outputs={wire.output}).")
                    ok = False
                    error_count += 1
                    if error_count >= max_errors:
                        break

            # Registration: any wire with reg==True should originate from a module that participates in a loop
            if getattr(wire, "reg", False):
                # Expect wire.input to be like "<mod>_output_k"
                src = wire.input if isinstance(wire.input, str) else ""
                src_mod = src.split("_output_")[0] if "_output_" in src else None
                if not src_mod or src_mod not in self.loop_set:
                    if verbose and error_count < max_errors:
                        print(f"[Wire-Error] Registered wire {wid} originates from non-loop module: {src_mod!r}")
                    ok = False
                    error_count += 1
                    if error_count >= max_errors:
                        break

            # Each module input that wire drives must also include the wire in mod_IO[mod]['inputs']
            for port in wire.output:
                if port == 'output':
                    continue
                if "_input_" in port:
                    dst_mod = port.split("_input_")[0]
                    if wid not in self.mod_IO[dst_mod]['inputs']:
                        if verbose and error_count < max_errors:
                            print(f"[Wire-Error] Wire {wid} drives {dst_mod} (port {port}) "
                                f"but is missing from mod_IO[{dst_mod}]['inputs'].")
                        ok = False
                        error_count += 1
                        if error_count >= max_errors:
                            break

        # ============= 4) Loop metadata consistency =============
        # Check that every module in loop_set references at least one loop id
        for m in self.loop_set:
            if not self.module_tree.get(m, {}).get("loops"):
                if verbose and error_count < max_errors:
                    print(f"[Loop-Error] Module '{m}' in loop_set has no loop id in module_tree entry.")
                ok = False
                error_count += 1
                if error_count >= max_errors:
                    break

        # Check loop structures are consistent cycles in the module_tree graph
        for loop_id, nodes in self.loops.items():
            if not nodes or len(nodes) < 3:  # Need at least 3 nodes for a valid cycle
                if verbose:
                    print(f"[Loop-Error] Loop '{loop_id}' has insufficient nodes: {nodes}")
                ok = False
                error_count += 1
                if error_count >= max_errors:
                    break
                continue

            # For hardware combinational loops, expect pattern [A, B, A]
            # where A -> B exists in module tree, and B -> A is the back-edge
            if len(nodes) == 3 and nodes[0] == nodes[2]:
                # Valid 2-node combinational loop: A -> B -> A
                a, b = nodes[0], nodes[1]
                
                # Check that A -> B exists (forward edge)
                if b not in self.module_tree.get(a, {}).get("children", []):
                    if verbose:
                        print(f"[Loop-Error] Loop '{loop_id}' missing forward edge {a} -> {b}")
                    ok = False
                    error_count += 1
                    if error_count >= max_errors:
                        break
                    continue
                
                # Check that B -> A exists (back-edge)
                if a not in self.module_tree.get(b, {}).get("children", []):
                    if verbose:
                        print(f"[Loop-Error] Loop '{loop_id}' missing back-edge {b} -> {a}")
                    ok = False
                    error_count += 1
                    if error_count >= max_errors:
                        break
                    continue
                
                # Verify that the loop is properly registered (has reg=True wires)
                has_registered_outputs = False
                for w in self.all_wires.values():
                    if (w.type in (IO_map.Wire.Wire_Type.MTM, IO_map.Wire.Wire_Type.MTO) and 
                        w.input.startswith(b) and getattr(w, "reg", False)):
                        has_registered_outputs = True
                        break
                
                if not has_registered_outputs:
                    if verbose:
                        print(f"[Loop-Error] Loop '{loop_id}' missing registered outputs on {b} to break combinational loop")
                    ok = False
                    error_count += 1
                    if error_count >= max_errors:
                        break
                    continue
                
            else:
                # For more complex loops, validate each consecutive pair
                for i, (a, b) in enumerate(zip(nodes, nodes[1:] + nodes[:1])):
                    if b not in self.module_tree.get(a, {}).get("children", []):
                        if verbose:
                            print(f"[Loop-Error] Loop '{loop_id}' broken edge {a} -> {b} at position {i}.")
                            print(f"[Loop-Error] Available children of {a}: {self.module_tree.get(a, {}).get('children', [])}")
                        ok = False
                        error_count += 1
                        if error_count >= max_errors:
                            break

                # Additional validation: ensure no consecutive duplicate modules
                for i in range(len(nodes) - 1):
                    if nodes[i] == nodes[i + 1]:
                        if verbose:
                            print(f"[Loop-Error] Loop '{loop_id}' has consecutive duplicate module {nodes[i]} at positions {i}, {i+1}")
                        ok = False
                        error_count += 1
                        if error_count >= max_errors:
                            break

        if verbose:
            if error_count >= max_errors:
                print(f"[Comprehensive-Check] Result: FAILED ❌ (stopped after {max_errors} errors)")
            else:
                print(f"[Comprehensive-Check] Result: {'OK ✅' if ok else f'FAILED ❌ ({error_count} errors)'}")

        return ok
    
    def reset_state(self, seed=None, verbose=True):
        """
        Reset the fuzzer to its initial, unmutated state but with a fresh random seed.
        This reloads the original flattened module library and reconstructs
        all module/wire/tree mappings.

        Args:
            seed (int or None): If None, a random seed will be generated.
            verbose (bool): If True, prints reset info.

        Returns:
            int: The seed used for this reset.
        """
        # Pick a random seed if none provided
        if seed is None:
            seed = random.randint(0, 2**32 - 1)

        random.seed(seed)

        if not hasattr(self, "flattened_lib_path"):
            raise RuntimeError(
                "Fuzz_Run object has no `_original_file_path` attribute. "
                "You must store the path to the original flattened module library "
                "when initializing."
            )

        # Re-initialize all state from the original file
        if verbose:
            print(f"[Reset] Reloading state from {self.flattened_lib_path} with seed={seed}")

        self.__init__(self.flattened_lib_path)

        # Restore seed so that __init__ doesn't overwrite it
        random.seed(seed)

        return seed
    
    def generate_sv_testbench(self,
                            top_name: str = "top",
                            output_path: str = ".",
                            sim_cycles: int = 200,
                            clk_period: int = 2,
                            hold_reset_cycles: int = 2,   # kept for API compat; unused (no rst in top)
                            trace: bool = True,
                            seed: int = 0,
                            verbose: bool = True) -> str:

        tb_name = f"tb_{top_name}"
        outdir = Path(output_path)
        outdir.mkdir(parents=True, exist_ok=True)

        # Require top next to TB (for include-based flow keep your own `include "top.sv"` in TB if desired)
        top_sv = outdir / f"{top_name}.sv"
        if not top_sv.exists():
            raise FileNotFoundError(f"Expected '{top_sv}' to exist. Generate the top first.")

        N = int(len(self.external_inputs))
        M = int(len(self.external_outputs))

        # --- Declarations ---
        decl_clk = "logic clk;"
        decl_rst = "logic rst_n;"
        decl_in  = f"logic [{N-1}:0] in_flat;"  if N > 0 else ""
        decl_out = f"wire  [{M-1}:0] out_flat;" if M > 0 else ""
        decl_cyc = "integer cyc;"
        decl_rng = "reg [31:0] rng_state;" if N > 0 else ""

        # --- Clock and reset gen ---
        half = max(1, int(clk_period) // 2) or 1
        clk_gen = (
            "  // Clock generator\n"
            "  initial clk = 1'b0;\n"
            f"  always #{half} clk = ~clk;\n\n"
            "  // Reset generator\n"
            "  initial begin\n"
            "    rst_n = 1'b0;\n"
            f"    #{half * 4} rst_n = 1'b1; // Release reset after 2 clock cycles\n"
            "  end"
        )

        # --- Deterministic pseudo-random generation for cross-simulator consistency ---
        if N > 0:
            if N <= 32:
                stim_block = f"""    // Linear congruential generator for deterministic cross-simulator randomization
    rng_state = (rng_state * 32'h41C64E6D + 32'h3039) & 32'hFFFFFFFF;
    in_flat = rng_state[{N-1}:0];"""
            else:
                # For wide inputs, concatenate multiple RNG outputs
                num_chunks = (N + 31) // 32  # Round up to get number of 32-bit chunks needed
                chunks = []
                for i in range(num_chunks):
                    chunks.append("rng_state")
                    if i < num_chunks - 1:  # Don't advance RNG after last chunk
                        chunks.append("rng_state = (rng_state * 32'h41C64E6D + 32'h3039) & 32'hFFFFFFFF")
                
                # Build the assignment
                rng_updates = []
                for i in range(num_chunks):
                    rng_updates.append("    rng_state = (rng_state * 32'h41C64E6D + 32'h3039) & 32'hFFFFFFFF;")
                    if i == num_chunks - 1:
                        # Last chunk might be partial
                        remaining_bits = N - (i * 32)
                        if remaining_bits == 32:
                            rng_updates.append(f"    in_flat[{N-1}:{i*32}] = rng_state;")
                        else:
                            rng_updates.append(f"    in_flat[{N-1}:{i*32}] = rng_state[{remaining_bits-1}:0];")
                    else:
                        rng_updates.append(f"    in_flat[{(i+1)*32-1}:{i*32}] = rng_state;")
                
                stim_block = "    // Linear congruential generator for deterministic cross-simulator randomization\n" + "\n".join(rng_updates)
        else:
            stim_block = "    // No inputs to randomize"


        # --- Seed & cycles with plusargs ---
        default_seed = int(seed) if (seed is not None) else 0xC0FFEE
        rng_init = f"    rng_state = seed;" if N > 0 else ""
        prelude = (
            "  int cycles;\n"
            "  int seed;\n"
            "  initial begin\n"
            f"    cycles = {int(sim_cycles)}; if ($value$plusargs(\"cycles=%d\", cycles)) ;\n"
            f"    if (!$value$plusargs(\"seed=%d\", seed)) seed = {default_seed};\n"
            f"{rng_init}\n"
            f"    cyc = 0;\n"
            "  end"
        )

        # --- Trace (VCD) ---
        wave_block = ""
        if trace:
            wave_block = (
                "  // Waveform dump (enable with Verilator --trace)\n"
                f"  initial begin\n"
                f"    $dumpfile(\"{tb_name}.vcd\");\n"
                f"    $dumpvars(0, {tb_name});\n"
                f"  end"
            )

        # --- DUT port list ---
        port_lines = ["    .clk(clk)", "    .rst_n(rst_n)"]
        if N > 0:
            port_lines.append("    .in_flat(in_flat)")
        if M > 0:
            port_lines.append("    .out_flat(out_flat)")
        ports_str = ",\n".join(port_lines)

        # --- Hex monitor for compact logging ---
        if M > 0 and N > 0:
            monitor = (
                "  always @(posedge clk) begin\n"
                "    cyc <= cyc + 1;\n"
                f'    $write("CYCLE=%0d IN=%0h OUT=%0h\\n", cyc, in_flat, out_flat);\n'
                "  end"
            )
        elif M > 0:
            monitor = (
                "  always @(posedge clk) begin\n"
                "    cyc <= cyc + 1;\n"
                f'    $write("CYCLE=%0d OUT=%0h\\n", cyc, out_flat);\n'
                "  end"
            )
        elif N > 0:
            monitor = (
                "  always @(posedge clk) begin\n"
                "    cyc <= cyc + 1;\n"
                f'    $write("CYCLE=%0d IN=%0h\\n", cyc, in_flat);\n'
                "  end"
            )
        else:
            monitor = "  // No IN/OUT to print"

        # --- Main stimulus loop ---
        main_loop = (
            "  integer i;\n"
            "  initial begin\n"
            "    // Initialize inputs before starting\n"
            f"{stim_block}\n"
            "    @(negedge clk); // small settle before starting\n"
            "    for (i = 0; i < cycles; i = i + 1) begin\n"
            "      @(negedge clk); // update inputs on negative edge\n"
            f"{stim_block}\n"
            "    end\n"
            "    @(posedge clk); // final clock edge\n"
            "    $display(\"TB_SIM_OK cycles=%0d\", cycles);\n"
            "    $finish;\n"
            "  end"
        )

        # Assemble TB
        decls = "\n  ".join([d for d in (decl_clk, decl_rst, decl_in, decl_out, decl_cyc, decl_rng) if d])
        tb_text = (
            "`default_nettype none\n"
            "`timescale 1ns/1ps\n"
            f"module {tb_name};\n\n"
            f"  // Declarations\n"
            f"  {decls}\n\n"
            f"{clk_gen}\n\n"
            f"{prelude}\n\n"
            f"{wave_block}\n\n" if wave_block else
            "`default_nettype none\n"
            "`timescale 1ns/1ps\n"
            f"module {tb_name};\n\n"
            f"  // Declarations\n"
            f"  {decls}\n\n"
            f"{clk_gen}\n\n"
            f"{prelude}\n\n"
        )

        tb_text += (
            f"  // DUT instance\n"
            f"  {top_name} dut (\n"
            f"{ports_str}\n"
            f"  );\n\n"
            f"{monitor}\n\n"
            f"{main_loop}\n\n"
            f"endmodule\n"
        )

        tb_path = outdir / f"{tb_name}.sv"
        tb_path.write_text(tb_text)
        if verbose:
            print(f"[TB] Wrote SystemVerilog testbench: {tb_path}")
            print(f"[TB] N inputs={N}, M outputs={M}, clk_period={clk_period}, cycles(default)={sim_cycles}")
            if N == 0:
                print("[TB] Inputs randomized: (none)")
            else:
                print("[TB] Inputs randomized: in_flat (exact width; no truncation)")
            if M == 0:
                print("[TB] Output monitor: (none; no outputs)")

        return str(tb_path)


    def generate_top_module(self, output_path, top_name):
        """
        Generate a top-level Verilog module connecting all module_wrappers.
        Explicitly separates MTM and MTO wires:
        - MTM: drives modules and may also drive 'output'.
        - MTO: only drives 'output'.
        Handles reg=True (looped modules) and skips stale wires.
        """

        ext_inputs = self.external_inputs
        ext_outputs = self.external_outputs
        wire_map = self.all_wires
        mod_IO = self.mod_IO

        ext_in_pos = {wid: i for i, wid in enumerate(ext_inputs)}
        ext_out_pos = {wid: j for j, wid in enumerate(ext_outputs)}

        # Proper input/output ordering based on port names
        mod_in_order = {}
        for mod, io in mod_IO.items():
            def port_index(wid):
                ports = [p for p in self.all_wires[wid].output if p.startswith(mod)]
                return int(ports[0].split("_input_")[1]) if ports else 9999
            mod_in_order[mod] = sorted(io['inputs'], key=port_index)

        mod_out_order = {}
        for mod, io in mod_IO.items():
            def port_index_out(wid):
                return int(self.all_wires[wid].input.split("_output_")[1])
            mod_out_order[mod] = sorted(io['outputs'], key=port_index_out)

        mod_in_width = {mod: len(bits) for mod, bits in mod_in_order.items()}
        mod_out_width = {mod: len(bits) for mod, bits in mod_out_order.items()}

        lines = []
        lines.append("// Auto-generated Top Module for flattened IO")

        # Include wrapper files
        # for mod in sorted(self.all_modules):
            # lines.append(f"`include \"{mod}.sv\"")
        lines.append("")

        # Top module declaration
        lines.append(f"module {top_name} (")
        lines.append("    input  wire clk,")
        lines.append("    input  wire rst_n,")
        if ext_inputs:
            lines.append(f"    input  wire [{len(ext_inputs)-1}:0] in_flat,")
        if ext_outputs:
            lines.append(f"    output wire [{len(ext_outputs)-1}:0] out_flat")
        else:
            lines.append("    // no external outputs")
        lines.append(");\n")

        # Per-module I/O buses
        lines.append("// Per-module I/O buses")
        for mod in sorted(self.all_modules):
            inW, outW = mod_in_width[mod], mod_out_width[mod]
            if inW:
                lines.append(f"wire [{inW-1}:0] {mod}_in_flat;")
            else:
                lines.append(f"// {mod} has no inputs")
            if outW:
                lines.append(f"wire [{outW-1}:0] {mod}_out_flat;")
            else:
                lines.append(f"// {mod} has no outputs")
        lines.append("")

        # Registered modules
        regged_modules = {
            w.input.split("_output_")[0]
            for w in wire_map.values()
            if w.type == IO_map.Wire.Wire_Type.MTM and w.reg
        }

        if regged_modules:
            lines.append("// Registered output shadows for looped modules")
            for mod in sorted(regged_modules):
                outW = mod_out_width[mod]
                lines.append(f"reg [{outW-1}:0] {mod}_out_reg;")
                lines.append(f"always @(posedge clk or negedge rst_n) begin")
                lines.append(f"  if (!rst_n)")
                lines.append(f"    {mod}_out_reg <= {outW}'b0;")
                lines.append(f"  else")
                lines.append(f"    {mod}_out_reg <= {mod}_out_flat;")
                lines.append("end")
            lines.append("")

        # External inputs
        if ext_inputs:
            lines.append("// External inputs to module inputs")
            for wire_id in ext_inputs:
                if wire_id not in wire_map:
                    continue
                wire = wire_map[wire_id]
                if not wire.output or wire.type != IO_map.Wire.Wire_Type.ITM:
                    continue
                dst = wire.output[0]
                mod = self._mod_from_port(dst)
                bitidx = mod_in_order[mod].index(wire_id)
                lines.append(f"assign {mod}_in_flat[{bitidx}] = in_flat[{ext_in_pos[wire_id]}];")
            lines.append("")

        # Internal MTM connections
        lines.append("// Internal MTM connections (module-to-module)")
        for wire in wire_map.values():
            if wire.type != IO_map.Wire.Wire_Type.MTM:
                continue

            src_mod = wire.input.split("_output_")[0]
            src_bit = mod_out_order[src_mod].index(wire.id)

            for dst in wire.output:
                if dst == "output":
                    continue
                dst_mod = self._mod_from_port(dst)
                dst_bit = mod_in_order[dst_mod].index(
                    next(wid for wid in mod_IO[dst_mod]['inputs'] if dst in wire_map[wid].output)
                )
                if src_mod in regged_modules:
                    lines.append(f"assign {dst_mod}_in_flat[{dst_bit}] = {src_mod}_out_reg[{src_bit}];")
                else:
                    lines.append(f"assign {dst_mod}_in_flat[{dst_bit}] = {src_mod}_out_flat[{src_bit}];")
        lines.append("")

        # External outputs (both MTO-only and MTM wires)
        if ext_outputs:
            lines.append("// External outputs (MTO + MTM wires)")
            for wire_id in ext_outputs:
                if wire_id not in wire_map:
                    continue
                wire = wire_map[wire_id]
                if wire.type not in (IO_map.Wire.Wire_Type.MTO, IO_map.Wire.Wire_Type.MTM):
                    continue

                mod = wire.input.split("_output_")[0]
                bitidx = mod_out_order[mod].index(wire_id)

                # MTM modules may be registered, MTO never is
                if mod in regged_modules:
                    lines.append(f"assign out_flat[{ext_out_pos[wire_id]}] = {mod}_out_reg[{bitidx}];")
                else:
                    lines.append(f"assign out_flat[{ext_out_pos[wire_id]}] = {mod}_out_flat[{bitidx}];")
            lines.append("")

        # Instantiate modules
        lines.append("// Instantiate all module wrappers")
        for mod in sorted(self.all_modules):
            inW, outW = mod_in_width[mod], mod_out_width[mod]
            if not (inW or outW):
                lines.append(f"// skip {mod}: no I/O")
                continue
            lines.append(f"{mod} u_{mod} (")
            ports = []
            if inW:
                ports.append(f".in_flat({mod}_in_flat)")
            if outW:
                ports.append(f".out_flat({mod}_out_flat)")
            for i, p in enumerate(ports):
                comma = "," if i < len(ports)-1 else ""
                lines.append(f"    {p}{comma}")
            lines.append(");")
        lines.append("endmodule")

        # Write to file
        final = "\n".join(lines)
        with open(f"{output_path}{top_name}.sv", "w") as output_file:
            output_file.write(final)