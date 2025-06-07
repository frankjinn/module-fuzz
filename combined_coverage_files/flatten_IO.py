#!/usr/bin/env python3
"""
generate_wrappers.py

This script scans a directory for SystemVerilog (.sv) files (one module per file),
parses each module’s port declarations, and generates a “flattened” wrapper for each
module such that:

  - All input bits are concatenated into a single wide input bus `in_flat`.
  - All output bits are concatenated into a single wide output bus `out_flat`.
  - The wrapper slices `in_flat` into the original input ports and wires them into
    the underlying module. Likewise, it collects all outputs from the underlying
    module and packs them into `out_flat`.

Additionally, each generated wrapper file now automatically includes the original
module’s file at the top (assuming the original file is named `<module>.sv`).

Usage:
    python3 generate_wrappers.py <input_directory> <output_directory>

Example:
    python3 generate_wrappers.py sv_sources wrappers_out

Result:
    For each file `foo.sv` containing `module foo (...)`, you’ll get a file
    `foo_wrapper.sv` in `wrappers_out/` that contains:

      `include "foo.sv"
      module foo_wrapper (...)
        ...
      endmodule
"""

import os
import re
import sys

###############################################################################
# Helper functions to parse one‐module‐per‐file SystemVerilog files
###############################################################################

def find_matching_paren(text: str, start_idx: int) -> int:
    depth = 1
    idx = start_idx + 1
    length = len(text)
    while idx < length:
        c = text[idx]
        if c == '(':
            depth += 1
        elif c == ')':
            depth -= 1
            if depth == 0:
                return idx
        idx += 1
    raise ValueError(f"No matching ')' found for '(' at index {start_idx}")


def parse_module_ports_from_text(text: str):
    module_match = re.search(r'^\s*module\s+(\w+)\b', text, flags=re.MULTILINE)
    if not module_match:
        raise RuntimeError("No 'module <name>' declaration found.")
    module_name = module_match.group(1)
    pos_after_name = module_match.end()

    idx = pos_after_name
    length = len(text)
    while idx < length and text[idx].isspace():
        idx += 1

    if idx < length and text[idx] == '#':
        param_open = text.find('(', idx)
        if param_open == -1:
            raise RuntimeError("Found '#' after module but no '(' for parameter block.")
        param_close = find_matching_paren(text, param_open)
        search_start = param_close + 1
    else:
        search_start = pos_after_name

    port_open = text.find('(', search_start)
    if port_open == -1:
        raise RuntimeError(f"No port-list '(' found for module '{module_name}'")
    port_close = find_matching_paren(text, port_open)
    port_list_text = text[port_open + 1 : port_close]

    port_lines = port_list_text.splitlines()
    input_ports = []
    output_ports = []
    range_pattern = re.compile(r'\[\s*(\d+)\s*:\s*(\d+)\s*\]')

    for raw_line in port_lines:
        line = raw_line.split('//', 1)[0].strip()
        if not line:
            continue
        line = line.rstrip(',;').strip()

        m_in = re.match(r'^\s*input\b(?:\s+(?:wire|reg))?(?:\s+signed)?(?:\s+(\[\s*\d+\s*:\s*\d+\s*\]))?\s+(\w+)\s*$', line)
        if m_in:
            range_str = m_in.group(1)
            port_name = m_in.group(2)
            if range_str:
                msb, lsb = map(int, re.findall(r'\d+', range_str))
                width = abs(msb - lsb) + 1
            else:
                width = 1
            input_ports.append((port_name, width))
            continue

        m_out = re.match(r'^\s*output\b(?:\s+(?:wire|reg))?(?:\s+signed)?(?:\s+(\[\s*\d+\s*:\s*\d+\s*\]))?\s+(\w+)\s*$', line)
        if m_out:
            range_str = m_out.group(1)
            port_name = m_out.group(2)
            if range_str:
                msb, lsb = map(int, re.findall(r'\d+', range_str))
                width = abs(msb - lsb) + 1
            else:
                width = 1
            output_ports.append((port_name, width))
            continue

    return module_name, input_ports, output_ports

###############################################################################
# Code to generate a flattened wrapper for a single module
###############################################################################

def generate_wrapper_sv(module_name: str,
                        input_ports: list,
                        output_ports: list) -> str:
    """
    Generates a flattened wrapper for `module_name` and includes the original module.
    """
    wrapper_name = f"{module_name}_wrapper"

    total_in_bits = sum(w for (_, w) in input_ports)
    total_out_bits = sum(w for (_, w) in output_ports)

    sv_lines = []
    # Add include for the original module
    sv_lines.append(f"`include \"{module_name}.sv\"")
    sv_lines.append("")
    sv_lines.append(f"//------------------------------------------------------------------------------")
    sv_lines.append(f"// Wrapper for {module_name}")
    sv_lines.append(f"// Flattens {len(input_ports)} inputs ({total_in_bits} bits) into `in_flat`,")
    sv_lines.append(f"// and flattens {len(output_ports)} outputs ({total_out_bits} bits) into `out_flat`.")
    sv_lines.append(f"//------------------------------------------------------------------------------")
    sv_lines.append(f"module {wrapper_name} (")
    sv_lines.append(f"    input  wire [{total_in_bits-1}:0] in_flat,")
    sv_lines.append(f"    output wire [{total_out_bits-1}:0] out_flat")
    sv_lines.append(f");")
    sv_lines.append("")

    sv_lines.append(f"  // Slice `in_flat` into original inputs")
    current_idx = total_in_bits - 1
    for port_name, width in input_ports:
        if width == 1:
            sv_lines.append(f"  wire {port_name} = in_flat[{current_idx}];")
            current_idx -= 1
        else:
            msb = current_idx
            lsb = current_idx - width + 1
            sv_lines.append(f"  wire [{width-1}:0] {port_name} = in_flat[{msb}:{lsb}];")
            current_idx -= width
    sv_lines.append("")

    sv_lines.append(f"  // Wires to capture original module outputs")
    for port_name, width in output_ports:
        if width == 1:
            sv_lines.append(f"  wire {port_name};")
        else:
            sv_lines.append(f"  wire [{width-1}:0] {port_name};")
    sv_lines.append("")

    sv_lines.append(f"  // Instantiate the original module")
    sv_lines.append(f"  {module_name} u_{module_name} (")
    all_ports = input_ports + output_ports
    for idx, (port_name, _) in enumerate(all_ports):
        comma = "," if idx < len(all_ports) - 1 else ""
        sv_lines.append(f"    .{port_name}({port_name}){comma}")
    sv_lines.append(f"  );")
    sv_lines.append("")

    sv_lines.append(f"  // Pack original outputs into `out_flat`")
    current_o_idx = total_out_bits - 1
    for port_name, width in output_ports:
        if width == 1:
            sv_lines.append(f"  assign out_flat[{current_o_idx}] = {port_name};")
            current_o_idx -= 1
        else:
            msb = current_o_idx
            lsb = current_o_idx - width + 1
            sv_lines.append(f"  assign out_flat[{msb}:{lsb}] = {port_name};")
            current_o_idx -= width
    sv_lines.append("")

    sv_lines.append(f"endmodule  // {wrapper_name}")
    return "\n".join(sv_lines)

###############################################################################
# Main driver: scan a directory for .sv files, generate one wrapper each
###############################################################################

def generate_wrappers_in_directory(input_dir: str, output_dir: str):
    os.makedirs(output_dir, exist_ok=True)

    for fname in os.listdir(input_dir):
        if not fname.lower().endswith(".sv"):
            continue
        input_path = os.path.join(input_dir, fname)
        with open(input_path, 'r') as f:
            text = f.read()

        try:
            module_name, input_ports, output_ports = parse_module_ports_from_text(text)
        except Exception as e:
            print(f"Skipping {fname}: {e}")
            continue

        wrapper_code = generate_wrapper_sv(module_name, input_ports, output_ports)
        out_fname = f"{module_name}_wrapper.sv"
        out_path = os.path.join(output_dir, out_fname)
        with open(out_path, 'w') as out_f:
            out_f.write(wrapper_code)
        print(f"Generated wrapper for module '{module_name}' → {out_path}")


if __name__ == "__main__":
    if len(sys.argv) != 3:
        print("Usage: python3 generate_wrappers.py <input_directory> <output_directory>")
        sys.exit(1)

    in_dir = sys.argv[1]
    out_dir = sys.argv[2]
    generate_wrappers_in_directory(in_dir, out_dir)
