#!/usr/bin/env python3
"""
IO_map.py

When given a folder of modules, generates a mapping of input and output ports to a key, 
which is a number that uniquely identifies the port.

Assumptions:
  1. No file has more than one module.
  2. No overlapping names for modules.

Usage as script:
    python3 IO_map.py path_to_module_library
"""

import os
import count_IO as count_IO

def list_all_files_walk(root_dir):
    """
    Recursively traverse `root_dir` and return a list of all file paths.
    """
    file_paths = []
    for dirpath, dirnames, filenames in os.walk(root_dir):
        for fname in filenames:
            full_path = os.path.join(dirpath, fname)
            file_paths.append(full_path)
    return file_paths

def create_IO_map(library_path):
    """
    Given a list of paths to Verilog/SystemVerilog files, create a mapping of input and output ports
    """
    in_map = {}
    out_map = {}
    input_port_counter = 0
    output_port_counter = 0

    paths = list_all_files_walk(library_path)
    if not paths:
        raise RuntimeError(f"No files found in directory: {library_path}")
    
    for path in paths:
        try:
            module_name, num_inputs, total_input_bits, num_outputs, total_output_bits = count_IO.parse_sv_ports(path)
        except RuntimeError as e:
            print(f"Error parsing {path}: {e}")
            continue

        # Map input ports
        for i in range(total_input_bits):
            input_value = f"{module_name}_input_{i}"
            in_map[input_port_counter] = input_value
            input_port_counter += 1


        for j in range(total_output_bits):
            output_value = f"{module_name}_output_{j}"
            out_map[output_port_counter] = output_value
            output_port_counter += 1

    io_map = {'input': in_map, 'output': out_map}
    return io_map