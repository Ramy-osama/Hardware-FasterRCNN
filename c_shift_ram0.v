`timescale 1ns / 1ps
 
module  c_shift_ram_0 #( parameter len = 2, wid = 4)(
input [wid-1:0]D,
input CLK,
input CE,
input SCLR,
output reg [wid-1:0] Q
);


reg [wid-1:0] sr2[len-1:0];

integer i;


 always@(posedge CLK)
 begin
if (SCLR) begin
 Q <=0;
end
else if(CE) begin

sr2[0] <= D;
end
if (len !== 1) begin
for(i=1; i<len ;i=i+1)
sr2[i] <= sr2[i-1];
end

 Q = sr2[len-1];

end
endmodule

