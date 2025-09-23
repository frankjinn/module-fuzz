#!/usr/bin/env python3
"""
IO_map.py

Optimized module for generating mappings of input and output ports to Wire objects.
Provides efficient Wire class and IO mapping functionality for module fuzzing.
"""

import os
from pathlib import Path
from typing import Dict, List, Set, Tuple, Union
from enum import Enum
import count_IO

class Wire:
    # M = module, I = input, O = output
    class Wire_Type(Enum):
        MTM = 1  # Module-to-Module
        ITM = 2  # Input-to-Module
        MTO = 3  # Module-to-Output

    def __init__(self, wire_id: int, wire_in: str, wire_out: str, wire_type: 'Wire.Wire_Type'):
        self.id = wire_id       # unique integer ID for this wire
        self.input = wire_in    # module that the wire input is attached to
        self.output = [wire_out] # list of modules this wire drives
        self.type = wire_type
        self.reg = False

    def __str__(self):
        """Return a human-readable description of the Wire."""
        return (f"Wire(id={self.id},"
                f"in='{self.input}', out={self.output}, reg={self.reg})")

    def __repr__(self):
        """Return an unambiguous string representation of the Wire."""
        return (f"Wire(id={self.id}, "
                f"in='{self.input}', out={self.output}, reg={self.reg})")

def list_all_files_walk(root_dir: Union[str, Path]) -> List[Path]:
    """Walk directory tree and return all .sv/.v file paths efficiently."""
    root_path = Path(root_dir)
    if not root_path.exists():
        raise RuntimeError(f"Directory does not exist: {root_dir}")
    
    # Use pathlib for more efficient file discovery
    return [p for p in root_path.rglob("*") if p.suffix.lower() in ('.sv', '.v')]

def create_IO_map(library_path: Union[str, Path]) -> Dict[str, Union[Dict, List, Set]]:
    """
    Optimized function to create IO mapping from .sv/.v files.
    
    Args:
        library_path: Path to directory containing module files
        
    Returns:
        Dictionary containing wire mappings and module information
    """
    # Initialize data structures with better type hints
    bitwise_in_map: Dict[int, Wire] = {}
    bitwise_out_map: Dict[int, Wire] = {}
    module_in_map: Dict[int, str] = {}
    module_out_map: Dict[int, str] = {}
    module_list: List[str] = []
    mod_IO: Dict[str, Dict[str, Set[int]]] = {}
    port_counter = 0

    file_paths = list_all_files_walk(library_path)
    if not file_paths:
        raise RuntimeError(f"No .sv/.v files found in directory: {library_path}")

    for file_path in file_paths:
        try:
            (module_name,
             num_inputs, total_input_bits,
             num_outputs, total_output_bits) = count_IO.parse_sv_ports(str(file_path))
        except RuntimeError as e:
            print(f"Warning: Skipping {file_path}: {e}")
            continue

        # Initialize module IO tracking
        mod_IO[module_name] = {'inputs': set(), 'outputs': set()}
        module_list.append(module_name)
        
        # Batch create input wires for better performance
        input_wire_ids = list(range(port_counter, port_counter + total_input_bits))
        for i, wire_id in enumerate(input_wire_ids):
            port_name = f"{module_name}_input_{i}"
            wire = Wire(wire_id, "input", port_name, Wire.Wire_Type.ITM)
            
            bitwise_in_map[wire_id] = wire
            module_in_map[wire_id] = module_name
            mod_IO[module_name]['inputs'].add(wire_id)
        
        port_counter += total_input_bits

        # Batch create output wires for better performance
        output_wire_ids = list(range(port_counter, port_counter + total_output_bits))
        for j, wire_id in enumerate(output_wire_ids):
            port_name = f"{module_name}_output_{j}"
            wire = Wire(wire_id, port_name, "output", Wire.Wire_Type.MTO)
            
            bitwise_out_map[wire_id] = wire
            module_out_map[wire_id] = module_name
            mod_IO[module_name]['outputs'].add(wire_id)
        
        port_counter += total_output_bits

    io_map = {
        'bit_input':  bitwise_in_map,
        'bit_output': bitwise_out_map,
        'mod_input':  module_in_map,
        'mod_output': module_out_map,
        'mod_list':   module_list,
        'mod_IO':     mod_IO
    }
    return io_map
