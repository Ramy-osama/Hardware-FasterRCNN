
void Max_Pooling(int image[r][c][d] ,int stride,int out[r/2][c/2][d])
{
int r1=0; // rows of output matrix
int c1=0; // columns of output matrix
// using 2x2 sub-window to compute the output
	for (int k=0;k<=2;k=k+1)
	{
		r1=0;
		c1=0;
	
for (int i=0;i<=(r-2);i=i+stride)
{
	for(int j=0;j<=(c-2);j=j+stride)
	{
	
		
		if((image[i][j][k]>=image[i+1][j][k])&&(image[i][j][k]>=image[i][j+1][k])&&(image[i][j][k]>=image[i+1][j+1][k]))
        {
        	out[r1][c1][k]=image[i][j][k];
        	c1++;
        		if ((c1==(c/2)) && (r1<((r/2)-1)))
        		{
        			c1=0;
        			r1++;
				}
        
        continue;
		}
else if ((image[i+1][j][k]>=image[i][j][k])&&(image[i+1][j][k]>=image[i][j+1][k])&&(image[i+1][j][k]>=image[i+1][j+1][k]))
 {
 	out[r1][c1][k]=image[i+1][j][k];
        	c1++;
        		if ((c1==(c/2)) && (r1<((r/2)-1)))
        		{
        			c1=0;
        			r1++;
				}
        
        	continue;
		}

else if((image[i][j+1][k]>=image[i+1][j][k])&&(image[i][j+1][k]>=image[i][j][k])&&(image[i][j+1][k]>=image[i+1][j+1][k])) 
 {
 		out[r1][c1][k]=image[i][j+1][k];
        	c1++;
        		if ((c1==(c/2)) && (r1<((r/2)-1)))
        		{
        			c1=0;
        			r1++;
				}
        
        continue;
		}

else if((image[i+1][j+1][k]>=image[i][j][k])&&(image[i+1][j+1][k]>=image[i][j+1][k])&&(image[i+1][j+1][k]>=image[i+1][j][k])) 
 {
 		out[r1][c1][k]=image[i+1][j+1][k];
        	c1++;
        			if ((c1==(c/2)) && (r1<((r/2)-1)))
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
