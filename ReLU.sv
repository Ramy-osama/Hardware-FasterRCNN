
module relu #(
	parameter Rows = 64,   // number of stream of bits
	parameter MSB=63, // most significant bit in the stream
        parameter Columns=64 //how many bits in each stream
        )(

	input clk,
	input rstn,
	input go,
	input en, //the enable button
	input	[Columns*Rows-1:0] data_i, //our input from the given image 
	output reg q_en,
	output reg [Columns*Rows-1:0] q //our ouptut to be assigned to the max_temp at the end
	);
	

	wire	[0:Rows-1][MSB:0]	d_in = data_i; //assigning our data inputs of the image to a 2D array 
	reg		[0:Rows-1][MSB:0]	max_temp; //this variable will be assigned to the output at the end
	
	genvar i;
	generate   //counter such that for each array to begin rectifying it
		for (i=0; i<Rows; i=i+1) begin : out_num
			always @ (posedge clk)
				if (!rstn)				max_temp[i] <= 0;
				else if (d_in[i][MSB])			max_temp[i] <= 0;
				else					max_temp[i] <= d_in[i];
		end
	endgenerate
	
	always @ (posedge clk) //the reset button and linking with the enable
		if (!rstn)	q_en <= 0;
		else 		q_en <= en;
	assign q = max_temp;
endmodule

