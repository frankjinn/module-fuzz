#!/usr/bin/env python3
"""
IO_map.py

When given a folder of modules, generates a mapping of input and output ports to a unique Wire object.
"""

import os
import count_IO as count_IO
from enum import Enum

class Wire:
    # M = module, I = input, O = output
    class Wire_Type(Enum):
        MTM = 1
        ITM = 2
        MTO = 3

    def __init__(self, wire_id, wire_in, wire_out, wire_type):

        self.id = wire_id       # unique integer ID for this wire
        self.input = wire_in       # module that the wire input is attached to
        self.output = [wire_out]   # list of modules this wire drives
        self.type = wire_type
        self.loops = set()

    def __str__(self):
        """
        Return a human-readable description of the Wire.
        """
        return (f"Wire(id={self.wire_id}, name='{self.wire_name}', "
                f"in='{self.wire_in}', out={self.wire_out})")

    def __repr__(self):
        """
        Return an unambiguous string representation of the Wire.
        """
        return (f"Wire(wire_id={self.wire_id}, wire_name='{self.wire_name}', "
                f"wire_in='{self.wire_in}', wire_out={self.wire_out})")

def list_all_files_walk(root_dir):
    file_paths = []
    for dirpath, dirnames, filenames in os.walk(root_dir):
        for fname in filenames:
            file_paths.append(os.path.join(dirpath, fname))
    return file_paths

def create_IO_map(library_path):
    """
    Given a folder of .sv/.v files, returns a dict with:
      - 'bit_input'  : { bit_index: Wire(...) }
      - 'bit_output' : { bit_index: Wire(...) }
      - 'mod_input'  : { bit_index: module_name }
      - 'mod_output' : { bit_index: module_name }
      - 'mod_list'   : [ module_name, ... ]
      - 'mod_IO'     : {'module': {'input': set(input_wire_idx), 'output': set(output_wire_idx)} }
    """
    bitwise_in_map  = {}
    bitwise_out_map = {}
    module_in_map   = {} 
    module_out_map  = {}
    module_list     = []
    mod_IO          = {}
    port_counter  = 0

    file_paths = list_all_files_walk(library_path)
    if not file_paths:
        raise RuntimeError(f"No files found in directory: {library_path}")

    for file_path in file_paths:
        try:
            (module_name,
             num_inputs, total_input_bits,
             num_outputs, total_output_bits) = count_IO.parse_sv_ports(file_path)
        except RuntimeError as e:
            print(f"Error parsing {file_path}: {e}")
            continue

        mod_IO[module_name] = {'inputs':set(), 'outputs':set()}
        module_list.append(module_name)
        # create Wire objects for every input bit
        for i in range(total_input_bits):
            port_name = f"{module_name}_input_{i}"
            w = Wire(port_counter, "input", port_name, Wire.Wire_Type.ITM)

            bitwise_in_map[port_counter] = w
            module_in_map[port_counter] = module_name
            mod_IO[module_name]['inputs'].add(port_counter)

            port_counter += 1


        # create Wire objects for every output bit
        for j in range(total_output_bits):
            wire_name = f"{module_name}_output_{j}"

            w = Wire(port_counter, module_name, "output", Wire.Wire_Type.MTO)
            bitwise_out_map[port_counter] = w
            module_out_map[port_counter] = module_name
            mod_IO[module_name]['outputs'].add(port_counter)

            port_counter += 1

    io_map = {
        'bit_input':  bitwise_in_map,
        'bit_output': bitwise_out_map,
        'mod_input':  module_in_map,
        'mod_output': module_out_map,
        'mod_list':   module_list,
        'mod_IO':     mod_IO
    }
    return io_map
