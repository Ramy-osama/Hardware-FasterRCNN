#include <iostream>
#include<stdio.h>
#include<vector>
#include <stdlib.h> 
#include<time.h> 
#define r 6
#define c 6
using namespace std;
void Max_Pooling(int image[r][c] ,int stride);
int main() {
int stride=2;
int image [r][c];
  srand(time(0));
		for(int i=0;i<=r-1;i++)
		{
			for(int j=0;j<=c-1;j++)
			{
				image[i][j]=rand()%100;
			}
		}
	

for(int i=0;i<=r-1;i++)// print the output
{
	cout<<"\n";
	for(int j=0;j<=c-1;j++)
	{
		cout<<image[i][j]<<" ";
		
	}
}
cout<<endl;
  Max_Pooling(image,stride);
return 0;
}
