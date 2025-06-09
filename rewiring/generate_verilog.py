import IO_map
import random
import re

def generate_connections(io_map, input_size, output_size = None, output_internal_wires = False, random_internal_assignment = False):
    """
    Generates the internal and external connections with the full library of modules given, referenced with the keys in the IO_map.
    Args:
        io_map: Map of wires with unique enumerated number as key, and port name as value.
        input_size: Desired input size into module.
        output_size: Automatically if not set, may be changed if set depending on parameters.
        output_internal_wires: If outputs of the overall module should include internally connected output wires
        random_internal_assignment: If false, each internal output will attempt to be used at least once, leaving minimal hanging wires.

    Returns:
        (connections, external_input_set, external_output_set): Length-2 list of internal outputs and internal inputs. List of external input ports to the module. List of external output ports to the module

    """
    assert(input_size <= len(io_map['input']))
    if output_size:
        assert(output_size <= len(io_map['output']))

    input_sample_space = len(io_map['input'])
    output_sample_space = len(io_map['output'])

    # Since external inputs to the module is always defined, we can set them immediately.
    external_input_set = random.sample(range(input_sample_space), input_size)

    # Since no internal input should be set more than once, we ensure to remove them from the choices that 
    # internal inputs can draw from.
    internal_input_set = set(range(input_sample_space))
    for i in external_input_set:
        internal_input_set.remove(i)

    # If we're not doing random_internal_assignment or output_internal_wires, then output_size can be determined
    if not random_internal_assignment and not output_internal_wires:
        if not output_size or (len(io_map['input']) - input_size) < len(io_map['output']):
            output_size = len(io_map['output']) - len(io_map['input']) + input_size
    
    connections = []

    # Enumerate the ports that are internal outputs.
    internal_output_list = list(range(output_sample_space))

    # If we are not outputting internal wires or doing random internal assignment,
    # they must not be connected internally. So they are removed from the sample space.
    if not (output_internal_wires or random_internal_assignment):
        external_output_set = random.sample(range(output_sample_space), k=output_size)
        for i in external_output_set:
            internal_output_list.remove(i)

    if random_internal_assignment:
        # Random internal connections allows us to sample with repetition from the internal output sample space.
        internal_output_with_repetition = random.choices(internal_output_list, k=len(internal_input_set))
        connections.append(internal_output_with_repetition)

        # We must find the internal outputs that have not been assigned to an input. These will become external outputs.
        unwired_connections = list(set(internal_output_list) - set(internal_output_with_repetition))

        if output_size:
            # If the number of unwired connection is >= output_size, then ignore and return all unwired connections.
            if len(unwired_connections) >= output_size:
                external_output_set = unwired_connections
            else:
                # If the user demands more outputs than the unwired connections can provide, we either sample (with no replacement) 
                # internally connected output wires, or we can just ignore the user demand if that is not an option.
                if output_internal_wires:
                    external_output_set = unwired_connections + random.sample(internal_output_with_repetition, output_size - len(unwired_connections))
                else:
                    external_output_set = unwired_connections
        else:
            # If there is no user demanded output size, we can output all output wires if allowed, or just the unwired internal outputs.
            if output_internal_wires:
                external_output_set = output_sample_space
            else:
                external_output_set = unwired_connections

    else:
        # Shuffle all the output ports
        random.shuffle(internal_output_list)

        if output_internal_wires:
            # Split all the internal outputs into wired and unwired groups
            unwired_connections = internal_output_list[len(internal_input_set):]
            wired_connections = internal_output_list[:len(internal_input_set)]
            if output_size:
                # If an output_size is specified, ignore if we have more unwired internal outputs than output_size.
                if len(unwired_connections) >= output_size:
                    external_output_set = unwired_connections
                
                # Sample from internal outputs if output_size is more than unwired connections.
                # Otherwise output all the unwired_connections.
                else:
                    if (output_size - len(unwired_connections)) > 0:
                        external_output_set = unwired_connections + random.sample(internal_output_list[:len(internal_input_set)], output_size - len(unwired_connections))
                    else:
                        external_output_set = unwired_connections
            else:
                # Output all wires if no output width is specified.
                external_output_set = unwired_connections + wired_connections
            connections.append(wired_connections)
        else:
            # If theres more internal inputs than internal outputs, then we connect internal outputs to more than 1 internal input.
            if len(internal_input_set) > len(internal_output_list):
                connections.append(internal_output_list)
                connections[0].extend(random.choices(internal_output_list, k=(len(internal_input_set) - len(internal_output_list))))
            elif len(internal_input_set) == len(internal_output_list):
                connections.append(internal_output_list)

            # At this point, there should never be a case where we have more internal outputs than inputs. Since they would have been
            # determined to be external outputs beforehand.
            else:
                ValueError("internal_input_set < internal_output_set")

    # Shuffle the internal input list.
    internal_input_list = list(internal_input_set)
    random.shuffle(internal_input_list)
    connections.append(internal_input_list)

    return (connections, external_input_set, external_output_set)

"""
Given:
  • io_map: a dict with two keys 'input' and 'output', each mapping a global_bit_index
    → "<module>_input_<bitIdx>" or "<module>_output_<bitIdx>"
  • connections: a two‐element list [internal_outputs, internal_inputs], where each is 
    a list of global_bit_indices of equal length.  For each k:
      internal_outputs[k] is the source global‐output bit;
      internal_inputs[k]  is the destination global‐input bit.
  • external_inputs:  list of global_bit_indices to expose as top‐level inputs
  • external_outputs: list of global_bit_indices to expose as top‐level outputs

Generates a Verilog “top” module that:
 1. Declares `input  wire [N_ext_in-1:0] in_flat;`
    where `N_ext_in = len(external_inputs)` and each bit `in_flat[i]` corresponds to 
    `global = external_inputs[i]`.
 2. Declares `output wire [N_ext_out-1:0] out_flat;`
    where `N_ext_out = len(external_outputs)` and each bit `out_flat[j]` corresponds to 
    `global = external_outputs[j]`.
 3. For each distinct module in io_map (e.g. "const_partselect_wrapper"), declares:
       wire [inWidth-1:0]  <mod>_in_flat;
       wire [outWidth-1:0] <mod>_out_flat;
    where inWidth = number of bits that module consumes, outWidth = number of bits it produces.
 4. Assigns:
       a) Top‐level inputs → module inputs:
            Let global = external_inputs[i], and io_map['input'][global] = "<mod>_input_<bitIdx>".
            Then generate:
              assign <mod>_in_flat[bitIdx] = in_flat[i];
       b) Module outputs → Top‐level outputs:
            Let global = external_outputs[j], and io_map['output'][global] = "<mod>_output_<bitIdx>".
            Then generate:
              assign out_flat[j] = <mod>_out_flat[bitIdx];
       c) Internal connections:
            For each pair (srcG, dstG) in connections:
              io_map['output'][srcG] = "<srcMod>_output_<srcBit>"
              io_map['input'][dstG]  = "<dstMod>_input_<dstBit>"
            Then:
              assign <dstMod>_in_flat[dstBit] = <srcMod>_out_flat[srcBit];
 5. Instantiates each module wrapper as:
       <mod> u_<mod> (
         .in_flat  (<mod>_in_flat),
         .out_flat (<mod>_out_flat)
       );

Usage:
    from top_module_generator import generate_top_module
    verilog_text = generate_top_module(io_map, connections,
                                       external_inputs, external_outputs)
    print(verilog_text)
"""


def generate_top_module(io_map, connections, external_inputs, external_outputs):
    """
    Args:
        io_map (dict): as before
        connections (list of two lists): as before
        external_inputs (list of int): as before
        external_outputs (list of int): as before

    Returns:
        Verilog text for `top`, with `include` directives for each module `<mod>.sv`.
    """
    # Build lookups
    N_ext_in  = len(external_inputs)
    N_ext_out = len(external_outputs)
    ext_in_pos  = { g: i for i, g in enumerate(external_inputs) }
    ext_out_pos = { g: j for j, g in enumerate(external_outputs) }

    # 1) Parse io_map to collect per-module bit‐widths
    mod_in_bits, mod_out_bits = {}, {}
    in_re  = re.compile(r'^(\w+)_input_(\d+)$')
    out_re = re.compile(r'^(\w+)_output_(\d+)$')

    for gidx, name in io_map['input'].items():
        m = in_re.match(name)
        if not m: raise RuntimeError(f"Bad input name: {name}")
        mod, bit = m.group(1), int(m.group(2))
        mod_in_bits.setdefault(mod, set()).add(bit)
    for gidx, name in io_map['output'].items():
        m = out_re.match(name)
        if not m: raise RuntimeError(f"Bad output name: {name}")
        mod, bit = m.group(1), int(m.group(2))
        mod_out_bits.setdefault(mod, set()).add(bit)

    all_mods = set(mod_in_bits) | set(mod_out_bits)
    for mod in all_mods:
        mod_in_bits.setdefault(mod, set())
        mod_out_bits.setdefault(mod, set())

    mod_in_width  = {mod: (max(s)+1 if s else 0) for mod, s in mod_in_bits.items()}
    mod_out_width = {mod: (max(s)+1 if s else 0) for mod, s in mod_out_bits.items()}

    # 2) Begin generating Verilog
    lines = []

    # 2a) Automatically include each module wrapper file
    for mod in sorted(all_mods):
        lines.append(f"`include \"{mod}.sv\"")
    lines.append("")

    # 2b) Module top declaration
    lines.append("// Automatically generated top module")
    lines.append("module top (")
    if N_ext_in:
        lines.append(f"    input  wire [{N_ext_in-1}:0] in_flat,")
    else:
        lines.append("    // no external inputs")
    if N_ext_out:
        lines.append(f"    output wire [{N_ext_out-1}:0] out_flat")
    else:
        lines.append("    // no external outputs")
    lines.append(");\n")

    # 3) Per-module flattened buses
    lines.append("  // Per-module flattened I/O buses")
    for mod in sorted(all_mods):
        inW, outW = mod_in_width[mod], mod_out_width[mod]
        if inW:
            lines.append(f"  wire [{inW-1}:0] {mod}_in_flat;")
        else:
            lines.append(f"  // {mod} has no inputs")
        if outW:
            lines.append(f"  wire [{outW-1}:0] {mod}_out_flat;")
        else:
            lines.append(f"  // {mod} has no outputs")
    lines.append("")

    # 4) Drive module inputs from in_flat
    if N_ext_in:
        lines.append("  // Drive module inputs from top-level in_flat")
        for g in sorted(external_inputs):
            pos = ext_in_pos[g]
            m = in_re.match(io_map['input'][g])
            mod, bit = m.group(1), int(m.group(2))
            lines.append(f"  assign {mod}_in_flat[{bit}] = in_flat[{pos}];")
        lines.append("")

    # 5) Internal connections
    outs, ins = connections
    if outs:
        lines.append("  // Internal connections: module-out → module-in")
        for srcG, dstG in zip(outs, ins):
            msrc = out_re.match(io_map['output'][srcG])
            dstm = in_re.match(io_map['input'][dstG])
            lines.append(f"  assign {dstm.group(1)}_in_flat[{dstm.group(2)}] = {msrc.group(1)}_out_flat[{msrc.group(2)}];")
        lines.append("")

    # 6) Drive out_flat from module outputs
    if N_ext_out:
        lines.append("  // Drive top-level out_flat from module outputs")
        for g in sorted(external_outputs):
            pos = ext_out_pos[g]
            m = out_re.match(io_map['output'][g])
            lines.append(f"  assign out_flat[{pos}] = {m.group(1)}_out_flat[{m.group(2)}];")
        lines.append("")

    # 7) Instantiate each module wrapper
    lines.append("  // Instantiate each module's wrapper")
    for mod in sorted(all_mods):
        inW, outW = mod_in_width[mod], mod_out_width[mod]
        if not (inW or outW):
            lines.append(f"  // skip {mod}: no I/O")
            continue
        lines.append(f"  {mod} u_{mod} (")
        ports = []
        if inW:  ports.append(f"    .in_flat  ({mod}_in_flat)")
        if outW: ports.append(f"    .out_flat ({mod}_out_flat)")
        for idx, p in enumerate(ports):
            lines.append(p + ("," if idx < len(ports)-1 else ""))
        lines.append("  );")
    lines.append("\nendmodule")

    return "\n".join(lines)

def generate_verilog(library_folder, output_folder, input_size, output_size = None, output_internal_wires = False, random_internal_assignment = False):
    random.seed(a=1)
    io_map = IO_map.create_IO_map(library_folder)
    (connections, external_input_set, external_output_set) = generate_connections(io_map, input_size, output_size, output_internal_wires, random_internal_assignment)
    verilog_file = generate_top_module(io_map, connections, external_input_set, external_output_set)

    with open(output_folder + "/my_file.sv", "w") as file:
        file.write(verilog_file)