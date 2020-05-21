module maxPooling(
    	input clk,
	input  [7:0] input1,
	input  [7:0] input2,
	input  [7:0] input3,
	input  [7:0] input4,
	input enable,
    	output reg [7:0] output1,
	output reg maxPoolingDone
    );
	 
	
	
	always @ (posedge clk) begin
		if(enable) begin
			if((input1>input2)&&(input1>input3)&&(input1>input4)) begin
				output1=input1;
maxPoolingDone=1;
end
else if((input2>input1)&&(input2>input3)&&(input2>input4))
begin
output1=input2;
maxPoolingDone=1;
end 
else if((input3>input1)&&(input3>input2)&&(input3>input4))
begin 
output1=input3;
maxPoolingDone=1;
end

else if((input4>input1)&&(input4>input2)&&(input4>input3))
begin
output1=input4;
maxPoolingDone=1;
end
end
end
endmodule

