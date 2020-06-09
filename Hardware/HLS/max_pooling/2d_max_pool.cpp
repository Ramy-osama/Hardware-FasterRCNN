void Max_Pooling(int image[r][c] ,int stride)
{
int r1=0; // rows of output matrix
int c1=0; // columns of output matrix
int out[r/2][c/2];
// using 2x2 sub-window to compute the output
	
for (int i=0;i<=(r-2);i=i+stride)
{
	for(int j=0;j<=(c-2);j=j+stride)
	{
	
		
		if((image[i][j]>=image[i+1][j])&&(image[i][j]>=image[i][j+1])&&(image[i][j]>=image[i+1][j+1]))
        {
        	out[r1][c1]=image[i][j];
        	c1++;
        		if ((c1==(c/2)) && (r1<((r/2)-1)))
        		{
        			c1=0;
        			r1++;
				}
        
        continue;
		}
else if ((image[i+1][j]>=image[i][j])&&(image[i+1][j]>=image[i][j+1])&&(image[i+1][j]>=image[i+1][j+1]))
 {
 	out[r1][c1]=image[i+1][j];
        	c1++;
        		if ((c1==(c/2)) && (r1<((r/2)-1)))
        		{
        			c1=0;
        			r1++;
				}
        
        	continue;
		}

else if((image[i][j+1]>=image[i+1][j])&&(image[i][j+1]>=image[i][j])&&(image[i][j+1]>=image[i+1][j+1])) 
 {
 		out[r1][c1]=image[i][j+1];
        	c1++;
        		if ((c1==(c/2)) && (r1<((r/2)-1)))
        		{
        			c1=0;
        			r1++;
				}
        
        continue;
		}

else if((image[i+1][j+1]>=image[i][j])&&(image[i+1][j+1]>=image[i][j+1])&&(image[i+1][j+1]>=image[i+1][j])) 
 {
 		out[r1][c1]=image[i+1][j+1];
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
c1--;
for(int i=0;i<=r1;i++)// print the output
{
	cout<<"\n";
	for(int j=0;j<=c1;j++)
	{
		cout<<out[i][j]<<" ";
		
	}
}
}
