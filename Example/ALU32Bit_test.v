`timescale 1ns / 1ps
module ALU32Bit_test(sys_clk, ALUControl, A, B, ALUResult); //set all variables outputs
input sys_clk;
output reg [3:0] ALUControl;
output reg [31:0] A, B;
output wire [31:0]  ALUResult;
wire Zero;
ALU32Bit uut (
    .ALUControl(ALUControl),
    .A(A),
    .B(B),
    .ALUResult(ALUResult),
    .Zero(Zero)
    );

always @(posedge sys_clk or negedge sys_clk) begin
    case($time)
        0: begin
            /*CLK = 1'b0;*/ALUControl = 0;A = 32'b00000000000000000000000000000010; B = 32'b00000000000000000000000000000010;//$display("hello world!!");
        end
        2: begin
        ALUControl = 1;A = 32'b00000000000000000000000000000010;
        end
        4: ALUControl = 3;
        6: ALUControl = 9;
        8: ALUControl = 10;
        10: ALUControl = 12;
        12: ALUControl = 13;
        14: ALUControl = 14;
        16: begin
            ALUControl = 5; B = 32'b00000000000000000000000000000110;
        end
        default: begin
        A = A + 2; B = B + 3; ALUControl = $time % 15;
        end
    endcase
    // if ($time == 200) $finish;
    // s = ("[%0t] A=%0d B=%0d ALUControl=%0d, ALUResult=%0d", $time, A, B, ALUControl, ALUResult);
    // $display("[%0t] A=%0d B=%0d ALUControl=%0d, ALUResult=%0d\n", $time, A, B, ALUControl, ALUResult);
    
    // $display(s);
end
endmodule