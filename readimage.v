module readimage#(
  parameter     WIDTH  = 668, 
         HEIGHT  = 452
)(clk , dataout);

input clk;
output reg [7:0] dataout;

reg [7:0] memory [WIDTH*HEIGHT-1:0] ;
integer i =0; 

initial $readmemb("C:\Users\ahmed\Desktop\test_binary_file.txt",memory,0,WIDTH*HEIGHT-1);

always@(posedge clk)  

if(i <WIDTH*HEIGHT) begin
 dataout <= memory[i] ;
 i <= i + 1;
end


endmodule