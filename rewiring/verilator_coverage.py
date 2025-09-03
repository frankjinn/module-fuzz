#!/usr/bin/env python3
"""
Verilator Coverage Instrumentation Module

This module handles coverage collection for Verilator itself (not the Verilog files)
using gcov/gcovr. It captures coverage data after each fuzzing cycle and can generate
aggregated HTML reports at specified intervals.

The coverage captures how well the fuzzing exercises Verilator's internal code paths,
which is useful for understanding what parts of Verilator are being tested by the
generated testbenches.
"""

import json
import os
import shlex
import shutil
import subprocess
import sys
from pathlib import Path
from typing import Optional, List, Dict, Any
import glob


class VerilatorCoverageCollector:
    """
    Handles collection and aggregation of Verilator coverage data using gcov/gcovr.
    """
    
    def __init__(self, 
                 verilator_root: str,
                 coverage_dir: Path,
                 verbose: bool = False):
        """
        Initialize the coverage collector.
        
        Args:
            verilator_root: Path to VERILATOR_ROOT directory
            coverage_dir: Directory to store coverage data and reports
            verbose: Enable verbose logging
        """
        self.verilator_root = Path(verilator_root)
        self.coverage_dir = Path(coverage_dir)
        self.verbose = verbose
        
        # Ensure coverage directory exists
        self.coverage_dir.mkdir(parents=True, exist_ok=True)
        
        # Coverage data subdirectories
        self.json_dir = self.coverage_dir / "json"
        self.html_dir = self.coverage_dir / "html"
        self.json_dir.mkdir(parents=True, exist_ok=True)
        self.html_dir.mkdir(parents=True, exist_ok=True)
        
        # Verilator src directory (where coverage is collected)
        self.verilator_src = self.verilator_root / "src"
        
        if not self.verilator_src.exists():
            raise ValueError(f"Verilator src directory not found: {self.verilator_src}")
        
        # Check if gcovr is available
        self.gcovr_path = shutil.which("gcovr")
        if not self.gcovr_path:
            raise RuntimeError("gcovr not found. Please install gcovr: pip install gcovr")
        
        if self.verbose:
            print(f"[Coverage] Initialized with VERILATOR_ROOT={self.verilator_root}")
            print(f"[Coverage] Coverage data will be stored in: {self.coverage_dir}")
            print(f"[Coverage] Using gcovr: {self.gcovr_path}")
    
    def prepare_verilator_for_coverage(self) -> bool:
        """
        Prepare Verilator source for coverage collection.
        This includes running bisonpre and copying necessary files.
        
        Returns:
            True if preparation succeeded, False otherwise
        """
        try:
            # Change to Verilator src directory
            orig_cwd = os.getcwd()
            os.chdir(self.verilator_src)
            
            # Run bisonpre to generate verilog.c
            bisonpre_cmd = ["./bisonpre", "-d", "-v", "-o", "verilog.c", "verilog.y"]
            if self.verbose:
                print(f"[Coverage] Running: {' '.join(bisonpre_cmd)}")
            
            result = subprocess.run(bisonpre_cmd, 
                                  capture_output=True, 
                                  text=True,
                                  cwd=self.verilator_src)
            
            if result.returncode != 0:
                if self.verbose:
                    print(f"[Coverage] bisonpre failed: {result.stderr}")
                return False
            
            # Copy verilog.c and verilog.y to obj_opt if it exists
            obj_opt = self.verilator_src / "obj_opt"
            if obj_opt.exists():
                try:
                    shutil.copy2(self.verilator_src / "verilog.c", obj_opt)
                    shutil.copy2(self.verilator_src / "verilog.y", obj_opt)
                    if self.verbose:
                        print("[Coverage] Copied verilog.c and verilog.y to obj_opt")
                except Exception as e:
                    if self.verbose:
                        print(f"[Coverage] Warning: Could not copy to obj_opt: {e}")
            
            return True
            
        except Exception as e:
            if self.verbose:
                print(f"[Coverage] Error preparing Verilator for coverage: {e}")
            return False
        finally:
            os.chdir(orig_cwd)
    
    def collect_cycle_coverage(self, cycle_idx: int) -> bool:
        """
        Collect coverage data for a single fuzzing cycle.
        
        Args:
            cycle_idx: The cycle index for naming the coverage file
            
        Returns:
            True if coverage collection succeeded, False otherwise
        """
        json_file = self.json_dir / f"cycle_{cycle_idx:04d}.json"
        
        # Build gcovr command for JSON output
        cmd = [
            self.gcovr_path,
            "--json-pretty",
            "-o", str(json_file),
            "-e", r".*\.h$",  # Exclude header files
            "--gcov-exclude-directories", "obj_dbg",
            "--root", str(self.verilator_src)
        ]
        
        try:
            if self.verbose:
                print(f"[Coverage] Collecting coverage for cycle {cycle_idx}")
                print(f"[Coverage] Command: {' '.join(cmd)}")
            
            # Run from verilator src directory
            result = subprocess.run(cmd, 
                                  capture_output=True, 
                                  text=True,
                                  cwd=self.verilator_src)
            
            if result.returncode != 0:
                if self.verbose:
                    print(f"[Coverage] gcovr failed for cycle {cycle_idx}: {result.stderr}")
                return False
            
            # Verify JSON file was created and has content
            if not json_file.exists() or json_file.stat().st_size == 0:
                if self.verbose:
                    print(f"[Coverage] No coverage data generated for cycle {cycle_idx}")
                return False
            
            if self.verbose:
                print(f"[Coverage] Coverage data saved to: {json_file}")
            
            return True
            
        except Exception as e:
            if self.verbose:
                print(f"[Coverage] Error collecting coverage for cycle {cycle_idx}: {e}")
            return False
    
    def generate_merged_report(self, cycle_idx: int) -> Optional[Path]:
        """
        Generate a merged HTML coverage report from all collected JSON files.
        
        Args:
            cycle_idx: Current cycle index (used for report naming)
            
        Returns:
            Path to the generated HTML report, or None if failed
        """
        # Find all JSON files
        json_files = sorted(self.json_dir.glob("cycle_*.json"))
        
        if not json_files:
            if self.verbose:
                print("[Coverage] No JSON coverage files found for merging")
            return None
        
        # Create timestamped HTML directory
        html_report_dir = self.html_dir / f"report_cycle_{cycle_idx:04d}"
        html_report_dir.mkdir(parents=True, exist_ok=True)
        
        html_file = html_report_dir / "coverage_report.html"
        
        # Build gcovr command for HTML output with aggregation
        cmd = [
            self.gcovr_path,
            "--html",
            "--html-details",
            "-o", str(html_file),
            "--root", str(self.verilator_src)
        ]
        
        # Add all JSON files for aggregation
        for json_file in json_files:
            cmd.extend(["-a", str(json_file)])
        
        try:
            if self.verbose:
                print(f"[Coverage] Generating merged HTML report with {len(json_files)} cycles")
                print(f"[Coverage] Command: {' '.join(cmd)}")
            
            result = subprocess.run(cmd, 
                                  capture_output=True, 
                                  text=True,
                                  cwd=self.verilator_src)
            
            if result.returncode != 0:
                if self.verbose:
                    print(f"[Coverage] HTML report generation failed: {result.stderr}")
                return None
            
            if not html_file.exists():
                if self.verbose:
                    print("[Coverage] HTML report was not generated")
                return None
            
            if self.verbose:
                print(f"[Coverage] HTML report generated: {html_file}")
                print(f"[Coverage] Report covers {len(json_files)} fuzzing cycles")
            
            return html_file
            
        except Exception as e:
            if self.verbose:
                print(f"[Coverage] Error generating HTML report: {e}")
            return None
    
    def get_coverage_summary(self) -> Dict[str, Any]:
        """
        Get a summary of collected coverage data.
        
        Returns:
            Dictionary with coverage statistics
        """
        json_files = list(self.json_dir.glob("cycle_*.json"))
        html_reports = list(self.html_dir.glob("report_cycle_*/coverage_report.html"))
        
        summary = {
            "total_cycles": len(json_files),
            "json_files": [str(f) for f in sorted(json_files)],
            "html_reports": [str(f) for f in sorted(html_reports)],
            "coverage_dir": str(self.coverage_dir),
            "latest_html_report": str(sorted(html_reports)[-1]) if html_reports else None
        }
        
        # Try to extract coverage percentage from latest JSON file
        if json_files:
            try:
                latest_json = sorted(json_files)[-1]
                with open(latest_json, 'r') as f:
                    data = json.load(f)
                
                # Extract summary statistics if available
                if 'summary' in data:
                    summary['latest_coverage'] = data['summary']
                
            except Exception as e:
                if self.verbose:
                    print(f"[Coverage] Could not extract coverage stats: {e}")
        
        return summary
    
    def cleanup_old_data(self, keep_cycles: int = 50):
        """
        Clean up old coverage data to prevent disk space issues.
        
        Args:
            keep_cycles: Number of recent cycles to keep
        """
        try:
            # Clean up old JSON files
            json_files = sorted(self.json_dir.glob("cycle_*.json"))
            if len(json_files) > keep_cycles:
                for old_file in json_files[:-keep_cycles]:
                    old_file.unlink()
                    if self.verbose:
                        print(f"[Coverage] Removed old coverage data: {old_file}")
            
            # Clean up old HTML reports (keep fewer since they're larger)
            html_dirs = sorted(self.html_dir.glob("report_cycle_*"))
            keep_reports = max(3, keep_cycles // 10)  # Keep fewer HTML reports
            if len(html_dirs) > keep_reports:
                for old_dir in html_dirs[:-keep_reports]:
                    shutil.rmtree(old_dir)
                    if self.verbose:
                        print(f"[Coverage] Removed old HTML report: {old_dir}")
                        
        except Exception as e:
            if self.verbose:
                print(f"[Coverage] Error during cleanup: {e}")


def create_coverage_collector(verilator_root: str, 
                            coverage_dir: Path, 
                            verbose: bool = False) -> Optional[VerilatorCoverageCollector]:
    """
    Factory function to create a coverage collector with error handling.
    
    Args:
        verilator_root: Path to VERILATOR_ROOT
        coverage_dir: Directory for coverage data
        verbose: Enable verbose logging
        
    Returns:
        VerilatorCoverageCollector instance or None if creation failed
    """
    try:
        collector = VerilatorCoverageCollector(verilator_root, coverage_dir, verbose)
        
        # Try to prepare Verilator for coverage
        if not collector.prepare_verilator_for_coverage():
            if verbose:
                print("[Coverage] Warning: Could not prepare Verilator for coverage")
                print("[Coverage] Coverage collection may not work properly")
        
        return collector
        
    except Exception as e:
        if verbose:
            print(f"[Coverage] Failed to create coverage collector: {e}")
        return None


if __name__ == "__main__":
    # Simple test of the coverage collector
    import tempfile
    
    verilator_root = os.environ.get("VERILATOR_ROOT", "/opt/verilator")
    
    with tempfile.TemporaryDirectory() as tmpdir:
        coverage_dir = Path(tmpdir) / "coverage"
        
        collector = create_coverage_collector(verilator_root, coverage_dir, verbose=True)
        if collector:
            print("Coverage collector created successfully")
            summary = collector.get_coverage_summary()
            print(f"Coverage summary: {summary}")
        else:
            print("Failed to create coverage collector")
