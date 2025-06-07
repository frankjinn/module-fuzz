#!/usr/bin/env python3
"""
split_verilog_modules_with_comments.py

This script reads a Verilog/SystemVerilog file containing multiple module definitions
and writes each module (including its preceding comment block) into a separate file
named <module_name>.sv.
"""

import re
import os
import sys
import argparse

def split_modules(input_path, output_dir):
    # Read the entire input file
    with open(input_path, 'r') as f:
        content = f.read()

    # Regular expression to match:
    #   - Any contiguous block of comment lines (//...) immediately preceding 'module'
    #   - The 'module' keyword, module name, up through the matching 'endmodule'
    #
    # Explanation:
    #   (?:(?:^\s*//.*\n)+)?   → optionally match one or more lines that start with '//' (with optional leading whitespace)
    #   ^\s*module\s+(\w+)\b   → then match 'module <module_name>' at the start of a line (capturing the name)
    #   [\s\S]*?               → non-greedy match of any characters (including newlines) up to...
    #   ^\s*endmodule\b         → an 'endmodule' at the start of a line
    #
    # Flags:
    #   re.MULTILINE  → allow ^ to match at the start of any line
    #   re.DOTALL     → allow '.' to match newlines
    module_pattern = re.compile(
        r'(?:(?:^\s*//.*\n)+)?'      # optional block of one or more comment lines
        r'^\s*module\s+(\w+)\b'     # 'module <module_name>' at start of line
        r'[\s\S]*?'                 # non-greedy match until...
        r'^\s*endmodule\b',         # 'endmodule' at start of line
        re.MULTILINE
    )

    matches = module_pattern.finditer(content)
    modules_written = 0

    # Ensure output directory exists
    os.makedirs(output_dir, exist_ok=True)

    for match in matches:
        module_name = match.group(1)
        module_code = match.group(0).rstrip() + '\n'  # include comments + module ... endmodule

        # Construct output file path
        output_path = os.path.join(output_dir, f"{module_name}.sv")

        # Write the module code (with preceding comments) to its own file
        with open(output_path, 'w') as out_f:
            out_f.write(module_code)

        print(f"Wrote module '{module_name}' (with comments) to {output_path}")
        modules_written += 1

    if modules_written == 0:
        print("No modules (with preceding comment blocks) found in the input file.")
    else:
        print(f"Total modules written: {modules_written}")


def main():
    parser = argparse.ArgumentParser(
        description="Split a Verilog/SystemVerilog file into separate files per module, including comments above each module."
    )
    parser.add_argument(
        "input_file",
        help="Path to the Verilog/SystemVerilog file containing multiple modules."
    )
    parser.add_argument(
        "-o", "--output-dir",
        default="modules_out",
        help="Directory where individual module files will be written (default: modules_out)."
    )

    args = parser.parse_args()
    split_modules(args.input_file, args.output_dir)


if __name__ == "__main__":
    main()
