
#include"parampad.h"

void Max_Pooling(int image[depthpool][rowpool][columnpool] ,int stride,int out[depthpool][rowpool/2][columnpool/2])
{
int r1=0; // rows of output matrix
int c1=0; // columns of output matrix
// using 2x2 sub-window to compute the output
	for (int k=0;k<depthpool;k=k+1)
	{
		r1=0;
		c1=0;
	
for (int i=0;i<=(rowpool-2);i=i+stridenumber)
{
	for(int j=0;j<=(columnpool-1);j=j+stridenumber)
	{
	
		
		if((image[k][i][j]>=image[k][i+1][j])&&(image[k][i][j]>=image[k][i][j+1])&&(image[k][i][j]>=image[k][i+1][j+1]))
        {
        	out[k][r1][c1]=image[k][i][j];
        	c1++;
        		if ((c1==(columnpool/2)) && (r1<((rowpool/2)-1)))
        		{
        			c1=0;
        			r1++;
				}
        
        continue;
		}
else if ((image[k][i+1][j]>=image[k][i][j])&&(image[k][i+1][j]>=image[k][i][j+1])&&(image[k][i+1][j]>=image[k][i+1][j+1]))
 {
 	out[k][r1][c1]=image[k][i+1][j];
        	c1++;
        		if ((c1==(columnpool/2)) && (r1<((rowpool/2)-1)))
        		{
        			c1=0;
        			r1++;
				}
        
        	continue;
		}

else if((image[k][i][j+1]>=image[k][i+1][j])&&(image[k][i][j+1]>=image[k][i][j])&&(image[k][i][j+1]>=image[k][i+1][j+1])) 
 {
 		out[k][r1][c1]=image[k][i][j+1];
        	c1++;
        		if ((c1==(columnpool/2)) && (r1<((rowpool/2)-1)))
        		{
        			c1=0;
        			r1++;
				}
        
        continue;
		}

else if((image[k][i+1][j+1]>=image[k][i][j])&&(image[k][i+1][j+1]>=image[k][i][j+1])&&(image[k][i+1][j+1]>=image[k][i+1][j])) 
 {
 		out[k][r1][c1]=image[k][i+1][j+1];
        	c1++;
        			if ((c1==(columnpool/2)) && (r1<((rowpool/2)-1)))
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