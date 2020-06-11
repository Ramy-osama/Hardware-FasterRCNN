#include <iostream>
#include<stdio.h>
#include<vector>
#include <stdlib.h> 
#include<time.h> 
#define r 6
#define c 6
#define d 3
using namespace std;
void Max_Pooling(int image[r][c][d] ,int stride,int out[r/2][c/2][d]);
int main() {
int stride=2;
int image [r][c][d];
int out[r/2][c/2][d];
  srand(time(0));
	for (int k=0;k<=2;k=k+1) //initialize the input 
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
cout<<" input channel "<<k+1<< ".\n";
cout<<endl;
for(int i=0;i<=r-1;i++)// print the input
{
	cout<<"\n";
	for(int j=0;j<=c-1;j++)
	{
		cout<<image[i][j][k]<<" ";
		
	}
}
cout<<endl;
}
  Max_Pooling(image,stride,out);
  for(int k=0;k<=2;k++)
{
cout<<endl;
cout<<"output channel "<<k+1<< ".\n";
cout<<endl;
for(int i=0;i<=(r/2)-1;i++)// print the output
{
	cout<<"\n";
	for(int j=0;j<=(c/2)-1;j++)
	{
		cout<<out[i][j][k]<<" ";
		
	}
}
cout<<endl;
}
return 0;
}
