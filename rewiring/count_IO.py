#!/usr/bin/env python3
"""
count_IO.py

This module provides a function to parse a Verilog‐2005 / SystemVerilog (.sv) file
containing exactly one module (with ANSI‐style port declarations, one per line) and
extract:
  - The module name
  - The number of input ports
  - The total number of bits across all input ports
  - The number of output ports
  - The total number of bits across all output ports

Assumptions:
  1. Exactly one module per file.
  2. ANSI‐style port list, with one 'input...' or 'output...' declaration per line inside
     the parentheses following 'module <name> ( ... );'.
  3. Bit ranges are of the form [MSB:LSB] with decimal integers. If no range is present,
     that port is assumed to be 1 bit wide.
  4. Lines may have trailing comments (//); anything after '//' is ignored.

Usage as script:
    python3 count_IO.py <path_to_sv_file>

Example:
    $ python3 count_IO.py design.sv
    Module name: my_module
    Number of inputs: 3
    Total input bits: 10
    Number of outputs: 2
    Total output bits: 9
"""

import re
import sys


def _bits_from_range(range_str: str) -> int:
    """
    Given a string like '7:0' or '3:1', return the width = abs(msb - lsb) + 1.
    """
    msb, lsb = map(int, range_str.split(':'))
    return abs(msb - lsb) + 1


def parse_sv_ports(path: str):
    """
    Parse the single-module SV file at `path` and return:
        (module_name: str,
         num_inputs: int,
         total_input_bits: int,
         num_outputs: int,
         total_output_bits: int)

    Raises RuntimeError on parse failures.
    """
    with open(path, 'r') as f:
        lines = f.readlines()

    # 1) Find the 'module <name>' line
    module_name = None
    module_line_idx = None
    for idx, line in enumerate(lines):
        # strip comments
        code = line.split('//', 1)[0]
        m = re.match(r'\s*module\s+(\w+)\b', code)
        if m:
            module_name = m.group(1)
            module_line_idx = idx
            break

    if module_name is None:
        raise RuntimeError(f"No 'module <name>' declaration found in {path}")

    # 2) Collect all lines from the '(' after 'module' until the matching ')'
    #    Count parentheses to know where the port list ends.
    paren_depth = 0
    ports_section = []
    started = False

    for idx in range(module_line_idx, len(lines)):
        line = lines[idx]
        # Remove anything after '//' (strip single-line comments)
        code = line.split('//', 1)[0]

        # Look for '(' on the module line (could be same line or following lines)
        if not started:
            if '(' in code:
                started = True
                # Count all '(' and ')' in this line
                paren_depth += code.count('(') - code.count(')')
                # Capture everything after the first '('
                # (But we can just store whole line and process each port line later)
                ports_section.append(code)
        else:
            # Already inside port‐list region
            paren_depth += code.count('(') - code.count(')')
            ports_section.append(code)
            if paren_depth == 0:
                # We've reached the line containing the closing ')' of the port list
                break

    if not started or paren_depth != 0:
        raise RuntimeError(f"Could not locate matching parentheses for module ports in {path}")

    # 3) Now parse each line in ports_section to find 'input' and 'output' declarations
    num_inputs = 0
    total_input_bits = 0
    num_outputs = 0
    total_output_bits = 0

    # Regex to extract bit‐range if present, e.g. [7:0]
    range_pattern = re.compile(r'\[\s*(\d+)\s*:\s*(\d+)\s*\]')

    for raw_line in ports_section:
        line = raw_line.strip()
        # Skip if it doesn't start with 'input' or 'output'
        if line.startswith('input'):
            num_inputs += 1
            # Look for a range
            r = range_pattern.search(line)
            if r:
                width = _bits_from_range(f"{r.group(1)}:{r.group(2)}")
            else:
                width = 1
            total_input_bits += width

        elif line.startswith('output'):
            num_outputs += 1
            r = range_pattern.search(line)
            if r:
                width = _bits_from_range(f"{r.group(1)}:{r.group(2)}")
            else:
                width = 1
            total_output_bits += width

        # else: ignore lines that do not declare a port

    return module_name, num_inputs, total_input_bits, num_outputs, total_output_bits