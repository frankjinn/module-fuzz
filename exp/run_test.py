#!/usr/bin/env python3
import argparse, textwrap, subprocess, os, re, sys

TB_NAME      = "tb"
TB_SV_FILE   = f"{TB_NAME}.sv"
MAIN_CPP     = "sim_main.cpp"
OBJ_DIR      = "obj_dir"
WRAPPER_EXEC = os.path.join(OBJ_DIR, f"V{TB_NAME}")

TB_TEMPLATE = textwrap.dedent("""\
    `timescale 1ns/1ps
    `default_nettype none

    module {tb_name};
      parameter int IN_WIDTH  = {in_width};
      parameter int OUT_WIDTH = {out_width};
      parameter int CYCLES     = {cycles};

      // DUT interface
      logic clk = 0;
      logic rst_n;
      logic [IN_WIDTH-1:0]  in_flat;
      wire  [OUT_WIDTH-1:0] out_flat;

      // instantiate DUT
      top dut (
        .in_flat(in_flat),
        .out_flat(out_flat)
      );

      // counters
      integer i;
      integer z_count, x_count, normal_count;

      // clock
      always #5 clk = ~clk;

      initial begin
        $dumpfile("tb.vcd");
        $dumpvars(0, {tb_name});

        rst_n = 0;
        #10;
        rst_n = 1;

        z_count      = 0;
        x_count      = 0;
        normal_count = 0;

        for (i = 0; i < CYCLES; i++) begin
          @(posedge clk);
          in_flat = $urandom;

          #1; // wait for outputs

          // count bit-states
          for (int j = 0; j < OUT_WIDTH; j++) begin
            casez (out_flat[j])
              1'bz: z_count++;
              1'bx: x_count++;
              default: normal_count++;
            endcase
          end
        end

        $display("TOTAL_Z_BITS:      %0d", z_count);
        $display("TOTAL_X_BITS:      %0d", x_count);
        $display("TOTAL_NORMAL_BITS: %0d", normal_count);
        $finish;
      end
    endmodule
    """)

MAIN_CPP_TEMPLATE = textwrap.dedent("""\
    #include "V{tb_name}.h"
    #include "verilated.h"
    int main(int argc, char **argv) {{
      Verilated::commandArgs(argc, argv);
      V{tb_name}* tb = new V{tb_name};
      while (!Verilated::gotFinish()) {{
        tb->eval();
      }}
      delete tb;
      return 0;
    }}
    """)

def generate_tb(args):
    with open(TB_SV_FILE, "w") as f:
        f.write(TB_TEMPLATE.format(
            tb_name   = TB_NAME,
            in_width  = args.in_width,
            out_width = args.out_width,
            cycles    = args.cycles
        ))
    with open(MAIN_CPP, "w") as f:
        f.write(MAIN_CPP_TEMPLATE.format(tb_name=TB_NAME))
    print(f"Generated {TB_SV_FILE} + {MAIN_CPP}")

def run_verilator(args):
    # ensure output directory exists
    if os.path.isdir(OBJ_DIR):
        subprocess.run(["rm", "-rf", OBJ_DIR], check=True)
    cmd = [
        "verilator",
        "--cc",
        *args.dut,
        TB_SV_FILE,
        "--exe", MAIN_CPP,
        "--build",
        "--Mdir", OBJ_DIR
    ]
    print("Invoking Verilator:", " ".join(cmd))
    subprocess.run(cmd, check=True)

def run_simulation():
    print("Running simulation...")
    p = subprocess.run([WRAPPER_EXEC], stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
    if p.returncode != 0:
        print("Simulation failed:", p.stderr, file=sys.stderr)
        sys.exit(1)
    return p.stdout

def parse_and_report(output):
    z = int(re.search(r"TOTAL_Z_BITS:\s+(\d+)",      output).group(1))
    x = int(re.search(r"TOTAL_X_BITS:\s+(\d+)",      output).group(1))
    n = int(re.search(r"TOTAL_NORMAL_BITS:\s+(\d+)", output).group(1))
    print(output.strip())
    ratio = (z+x) / n if n else float('inf')
    print(f"\nRatio (Z+X) / NORMAL = {z + x} / {n} = {ratio:.3f}")

def main():
    p = argparse.ArgumentParser(
        description="Generate, build & run a generic SV TB that counts Z/X vs normal bits"
    )
    p.add_argument("--dut", nargs="+", required=True,
                   help="Verilog source(s) for your DUT (e.g., top.sv)")
    p.add_argument("--in_width",  type=int, required=True,
                   help="width of input bus in_flat")
    p.add_argument("--out_width", type=int, required=True,
                   help="width of output bus out_flat")
    p.add_argument("--cycles",    type=int, default=1000,
                   help="how many clock cycles to run")
    p.add_argument("--no-run", action="store_true",
                   help="only generate TB (don't compile/run)")
    args = p.parse_args()

    generate_tb(args)

    if args.no_run:
        print("Done. You can now manually invoke Verilator or run the sim.")
        return

    run_verilator(args)
    sim_out = run_simulation()
    parse_and_report(sim_out)

if __name__ == "__main__":
    main()
