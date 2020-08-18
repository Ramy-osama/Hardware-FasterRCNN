void Max_Pooling_2(float image[CONV2_OUTPUT_CHANNELS ][CONV2_OUTPUT_SIZE][CONV2_OUTPUT_SIZE] ,int POOL_STRIDE,float out[POOL2_CHANNELS][POOL2_OUTPUT_SIZE][POOL2_OUTPUT_SIZE])
{
int r1=0; // rows of output matrix
int c1=0; // columns of output matrix
// using 2x2 sub-window to compute the output
	for (int k=0;k<CONV2_OUTPUT_CHANNELS;k=k+1)
	{
		r1=0;
		c1=0;
	
for (int i=0;i<=(CONV2_OUTPUT_SIZE-2);i=i+POOL_STRIDE)
{
	for(int j=0;j<=(CONV2_OUTPUT_SIZE-2);j=j+POOL_STRIDE)
	{
	
		
		if((image[k][i][j]>=image[k+1][i][j])&&(image[k][i][j]>=image[k][i+1][j])&&(image[k][i][j]>=image[k+1][i+1][j]))
        {
        	out[k][r1][c1]=image[k][i][j];
        	c1++;
        		if ((c1==(CONV2_OUTPUT_SIZE/2)) && (r1<((CONV2_OUTPUT_SIZE/2)-1)))
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
        		if ((c1==(CONV2_OUTPUT_SIZE/2)) && (r1<((CONV2_OUTPUT_SIZE/2)-1)))
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
        		if ((c1==(CONV2_OUTPUT_SIZE/2)) && (r1<((CONV2_OUTPUT_SIZE/2)-1)))
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
        			if ((c1==(CONV2_OUTPUT_SIZE/2)) && (r1<((CONV2_OUTPUT_SIZE/2)-1)))
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
