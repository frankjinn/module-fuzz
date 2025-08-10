`timescale 1ns/1ps
                module tb_top;

                // Declarations
                // top port mirrors
                

                

                

                  // Waveform dump (enable with Verilator --trace)
                                initial begin
                                    $dumpfile("tb_top.vcd");
                                    $dumpvars(0, tb_top);
                                end

                // DUT instance
                top dut (
                    
                );

                  integer i;
                                initial begin
                                    $urandom(1366899751);
                                    for (i = 0; i < 200; i = i + 1) begin
                                    #1;
                                    // Randomize non-clock/reset inputs each cycle
                                    end
                                    $display("TB_SIM_OK cycles=%0d", 200);
                                    $finish;
                                end

                endmodule
                