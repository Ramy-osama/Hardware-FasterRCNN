/* module if window size k*k and the input activation window with the same size 
   next stage : make module for window selection
*/

module basic_conv1(clk,ce,weight1,global_rst,activation1,conv_op);

parameter data_width = 32;
parameter k = 9'd3;     // kernel size 
parameter s = 1;          //value of stride (horizontal and vertical stride are equal)
input clk,ce,global_rst;
input wire [(k*k)*data_width-1:0] activation1;  
input wire [(k*k)*data_width-1:0] weight1; //3*3 kernel each pixel reprenented in 32 bit
wire [data_width-1:0] weight [0:(k*k)-1];
wire [data_width-1:0] activation [0:(k*k)-1];
output reg [data_width-1:0] conv_op;
wire [data_width-1:0] tmp [k*k+1:0];


// unpacking arrays of activaions and weights
generate
genvar j; 
for (j=0; j<(k*k); j=j+1)
begin 
assign weight [j][((data_width)-1):0] = weight1[((data_width)*j) +: data_width]; 
end 
endgenerate

generate
genvar l;
for (l=0; l<(k*k); l=l+1) 
begin
assign activation[l][((data_width)-1):0] = activation1[((data_width)*l) +: data_width];
end 
endgenerate



assign tmp[0] = 0;

generate
genvar i;
for(i = 0; i<=k*k ;i=i+1)
begin 
       mac_manual mac(                     //implements a*b+c
  	.clk(clk), // input clk
  	.ce(ce), // input ce
  	.sclr(global_rst), // input sclr
  	.a(activation[i]), // activation input [15 : 0] a
  	.b(weight[i]), // weight input [15 : 0] b
  	.c(tmp[i]), // previous mac sum input [32 : 0] c
 	 .p(tmp[i+1]) // output [32 : 0] p
 	 );
     end    
endgenerate

 always@(posedge clk,posedge global_rst)
 begin
 
 if(global_rst)
 begin
 conv_op<=0;
 end
 else if(ce)
 begin
conv_op<= tmp[10];
 end
 end


endmodule 
