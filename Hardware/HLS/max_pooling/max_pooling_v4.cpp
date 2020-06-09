#include <iostream>
#include<stdio.h>
#include<vector>
#include <stdlib.h> 
#include<time.h> 
#define r 6
#define c 6
#define d 3
using namespace std;
void Max_Pooling(int image[r][c][d] ,int stride)
{
int r1=0; // rows of output matrix
int c1=0; // columns of output matrix
int out[r/2][c/2][d];
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
c1--;
for(int k=0;k<=2;k++)
{
cout<<endl;
cout<<"channel "<<k+1<< ".\n";
cout<<endl;
for(int i=0;i<=r1;i++)// print the output
{
	cout<<"\n";
	for(int j=0;j<=c1;j++)
	{
		cout<<out[i][j][k]<<" ";
		
	}
}
cout<<endl;
}
}
int main() {
int stride=2;
int image [r][c][d];
  srand(time(0));
	for (int k=0;k<=2;k=k+1)
	{
		for(int i=0;i<=r-1;i++)
		{
			for(int j=0;j<=c-1;j++)
			{
				image[i][j][k]=rand()%100;
			}
		}
	}
	
	for(int k=0;k<=2;k++)
{
	cout<<endl;
cout<<"channel "<<k+1<< ".\n";
cout<<endl;
for(int i=0;i<=r-1;i++)// print the output
{
	cout<<"\n";
	for(int j=0;j<=c-1;j++)
	{
		cout<<image[i][j][k]<<" ";
		
	}
}
cout<<endl;
}
  Max_Pooling(image,stride);
return 0;
}
