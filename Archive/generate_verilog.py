#!/usr/bin/env python3
import os
import IO_map
import random
import re


def generate_connections(io_map, input_size, output_size=None, output_internal_wires=False, random_internal_assignment=False):
    """
    Generates the internal and external connections with the full library of modules given, referenced with the keys in the IO_map.
    """
    assert input_size <= len(io_map['bit_input'])
    if output_size:
        assert output_size <= len(io_map['bit_output'])

    input_sample_space = len(io_map['bit_input'])
    output_sample_space = len(io_map['bit_output'])

    # pick external inputs
    external_input_set = random.sample(range(input_sample_space), input_size)

    # internal inputs are the rest
    internal_input_set = set(range(input_sample_space)) - set(external_input_set)

    # determine output_size if not using random/internal wiring
    if not random_internal_assignment and not output_internal_wires:
        if not output_size or (len(io_map['bit_input']) - input_size) < len(io_map['bit_output']):
            output_size = len(io_map['bit_output']) - len(io_map['bit_input']) + input_size

    connections = []
    internal_output_list = list(range(output_sample_space))

    # decide external outputs when no random/internal assignment
    if not (output_internal_wires or random_internal_assignment):
        external_output_set = random.sample(range(output_sample_space), k=output_size)
        for i in external_output_set:
            internal_output_list.remove(i)

    if random_internal_assignment:
        internal_output_with_repetition = random.choices(internal_output_list, k=len(internal_input_set))
        connections.append(internal_output_with_repetition)

        unwired_connections = list(set(internal_output_list) - set(internal_output_with_repetition))

        if output_size:
            if len(unwired_connections) >= output_size:
                external_output_set = unwired_connections
            else:
                if output_internal_wires:
                    external_output_set = unwired_connections + random.sample(internal_output_with_repetition, output_size - len(unwired_connections))
                else:
                    external_output_set = unwired_connections
        else:
            if output_internal_wires:
                external_output_set = list(range(output_sample_space))
            else:
                external_output_set = unwired_connections
    else:
        random.shuffle(internal_output_list)
        if output_internal_wires:
            unwired_connections = internal_output_list[len(internal_input_set):]
            wired_connections = internal_output_list[:len(internal_input_set)]
            if output_size:
                if len(unwired_connections) >= output_size:
                    external_output_set = unwired_connections
                else:
                    if (output_size - len(unwired_connections)) > 0:
                        external_output_set = unwired_connections + random.sample(internal_output_list[:len(internal_input_set)], output_size - len(unwired_connections))
                    else:
                        external_output_set = unwired_connections
            else:
                external_output_set = unwired_connections + wired_connections
            connections.append(wired_connections)
        else:
            if len(internal_input_set) > len(internal_output_list):
                connections.append(internal_output_list)
                connections[0].extend(random.choices(internal_output_list, k=(len(internal_input_set) - len(internal_output_list))))
            elif len(internal_input_set) == len(internal_output_list):
                connections.append(internal_output_list)
            else:
                raise ValueError("internal_input_set < internal_output_list")

    internal_input_list = list(internal_input_set)
    random.shuffle(internal_input_list)
    connections.append(internal_input_list)

    return connections, external_input_set, external_output_set


def generate_top_module(io_map, connections, external_inputs, external_outputs):
    """
    Generate the Verilog `top` module text, now using Wire objects from IO_map.
    """
    N_ext_in = len(external_inputs)
    N_ext_out = len(external_outputs)
    ext_in_pos  = {g: i for i, g in enumerate(external_inputs)}
    ext_out_pos = {g: j for j, g in enumerate(external_outputs)}

    # 1) determine per-module bit widths
    in_re  = re.compile(r'^(\w+)_input_(\d+)$')
    out_re = re.compile(r'^(\w+)_output_(\d+)$')

    mod_in_bits  = {}
    mod_out_bits = {}
    for gidx, wire in io_map['bit_input'].items():
        m = in_re.match(wire.wire_name)
        if not m:
            raise RuntimeError(f"Bad input wire name: {wire.wire_name}")
        mod, bit = m.group(1), int(m.group(2))
        mod_in_bits.setdefault(mod, set()).add(bit)
    for gidx, wire in io_map['bit_output'].items():
        m = out_re.match(wire.wire_name)
        if not m:
            raise RuntimeError(f"Bad output wire name: {wire.wire_name}")
        mod, bit = m.group(1), int(m.group(2))
        mod_out_bits.setdefault(mod, set()).add(bit)

    all_mods = set(mod_in_bits) | set(mod_out_bits)
    for mod in all_mods:
        mod_in_bits.setdefault(mod, set())
        mod_out_bits.setdefault(mod, set())

    mod_in_width  = {mod: (max(bits)+1 if bits else 0) for mod, bits in mod_in_bits.items()}
    mod_out_width = {mod: (max(bits)+1 if bits else 0) for mod, bits in mod_out_bits.items()}

    # 2a) include each module wrapper
    lines = []
    for mod in sorted(all_mods):
        lines.append(f"`include \"{mod}.sv\"")
    lines.append("")

    # 2b) module declaration
    lines.append("// Auto-generated top module")
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

    # 3) per-module buses
    lines.append("  // Per-module I/O buses")
    for mod in sorted(all_mods):
        inW  = mod_in_width[mod]
        outW = mod_out_width[mod]
        if inW:
            lines.append(f"  wire [{inW-1}:0] {mod}_in_flat;")
        else:
            lines.append(f"  // {mod} has no inputs")
        if outW:
            lines.append(f"  wire [{outW-1}:0] {mod}_out_flat;")
        else:
            lines.append(f"  // {mod} has no outputs")
    lines.append("")

    # 4) drive module inputs from in_flat
    if N_ext_in:
        lines.append("  // Drive module inputs from in_flat")
        for g in sorted(external_inputs):
            pos  = ext_in_pos[g]
            wire = io_map['bit_input'][g]
            m    = in_re.match(wire.wire_name)
            mod, bit = m.group(1), int(m.group(2))
            lines.append(f"  assign {mod}_in_flat[{bit}] = in_flat[{pos}];")
        lines.append("")

    # 5) internal connections
    outs, ins = connections
    if outs:
        lines.append("  // Internal connections")
        for srcG, dstG in zip(outs, ins):
            src_wire = io_map['bit_output'][srcG]
            dst_wire = io_map['bit_input'][dstG]
            msrc = out_re.match(src_wire.wire_name)
            dstm = in_re.match(dst_wire.wire_name)
            lines.append(f"  assign {dstm.group(1)}_in_flat[{dstm.group(2)}] = {msrc.group(1)}_out_flat[{msrc.group(2)}];")
        lines.append("")

    # 6) drive out_flat from module outputs
    if N_ext_out:
        lines.append("  // Drive out_flat from module outputs")
        for g in sorted(external_outputs):
            pos  = ext_out_pos[g]
            wire = io_map['bit_output'][g]
            m    = out_re.match(wire.wire_name)
            lines.append(f"  assign out_flat[{pos}] = {m.group(1)}_out_flat[{m.group(2)}];")
        lines.append("")

    # 7) instantiate modules
    lines.append("  // Instantiate modules")
    for mod in sorted(all_mods):
        inW  = mod_in_width[mod]
        outW = mod_out_width[mod]
        if not (inW or outW):
            lines.append(f"  // skip {mod}: no I/O")
            continue
        lines.append(f"  {mod} u_{mod} (")
        ports = []
        if inW:  ports.append(f"    .in_flat  ({mod}_in_flat)")
        if outW: ports.append(f"    .out_flat ({mod}_out_flat)")
        for idx, p in enumerate(ports):
            suffix = "," if idx < len(ports)-1 else ""
            lines.append(p + suffix)
        lines.append("  );")
    lines.append("\nendmodule")

    return "\n".join(lines)


def generate_verilog(library_folder, output_folder, input_size, output_size=None, output_internal_wires=False, random_internal_assignment=False):
    random.seed(1)
    io_map = IO_map.create_IO_map(library_folder)
    connections, ext_ins, ext_outs = generate_connections(io_map, input_size, output_size, output_internal_wires, random_internal_assignment)
    verilog_text = generate_top_module(io_map, connections, ext_ins, ext_outs)
    with open(os.path.join(output_folder, "top.sv"), "w") as f:
        f.write(verilog_text)
