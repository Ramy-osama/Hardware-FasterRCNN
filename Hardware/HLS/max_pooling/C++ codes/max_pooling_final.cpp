void Max_Pooling(float image[conv_op_channels][conv_op_size][conv_op_size] ,int stride,float out[conv_op_channels][conv_op_size/2][conv_op_size/2])
{
int r1=0; // rows of output matrix
int c1=0; // columns of output matrix
// using 2x2 sub-window to compute the output
	for (int k=0;k<conv_op_channels;k=k+1)
	{
		r1=0;
		c1=0;
	
for (int i=0;i<=(conv_op_size-2);i=i+stride)
{
	for(int j=0;j<=(conv_op_size-2);j=j+stride)
	{
	
		
		if((image[k][i][j]>=image[k+1][i][j])&&(image[k][i][j]>=image[k][i+1][j])&&(image[k][i][j]>=image[k+1][i+1][j]))
        {
        	out[k][r1][c1]=image[k][i][j];
        	c1++;
        		if ((c1==(conv_op_size/2)) && (r1<((conv_op_size/2)-1)))
        		{
        			c1=0;
        			r1++;
				}
        
        continue;
		}
else if ((image[k+1][i][j]>=image[k][i][j])&&(image[k+1][i][j]>=image[k][i+1][j])&&(image[k+1][i][j]>=image[k+1][i+1][j]))
 {
 	out[k][r1][c1]=image[k+1][i][j];
        	c1++;
        		if ((c1==(conv_op_size/2)) && (r1<((conv_op_size/2)-1)))
        		{
        			c1=0;
        			r1++;
				}
        
        	continue;
		}

else if((image[k][i+1][j]>=image[k+1][i][j])&&(image[k][i+1][j]>=image[k][i][j])&&(image[k][i+1][j]>=image[k+1][i+1][j])) 
 {
 		out[k][r1][c1]=image[k][i+1][j];
        	c1++;
        		if ((c1==(conv_op_size/2)) && (r1<((conv_op_size/2)-1)))
        		{
        			c1=0;
        			r1++;
				}
        
        continue;
		}

else if((image[k+1][i+1][j]>=image[k][i][j])&&(image[k+1][i+1][j]>=image[k][i+1][j])&&(image[k+1][i+1][j]>=image[k+1][i][j])) 
 {
 		out[k][r1][c1]=image[k+1][i+1][j];
        	c1++;
        			if ((c1==(conv_op_size/2)) && (r1<((conv_op_size/2)-1)))
        		{
        			c1=0;
        			r1++;
				}
        
        continue;
		}

	}
}
}
}
