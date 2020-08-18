#include <iostream>
#include<stdio.h>
#include<vector>
#include <stdlib.h> 
#define POOL2_CHANNELS 
#define POOL2_OUTPUT_SIZE 
#define POOL2_STRIDE 2
#define CONV2_OUTPUT_CHANNELS
#define CONV2_OUTPUT_SIZE
using namespace std;
void Max_Pooling_2(float image[CONV2_OUTPUT_CHANNELS][CONV2_OUTPUT_SIZE][CONV2_OUTPUT_SIZE] ,int POOL_STRIDE,float out[POOL2_CHANNELS][POOL2_OUTPUT_SIZE][POOL2_OUTPUT_SIZE]);
int main() {
float image[CONV2_OUTPUT_CHANNELS ][CONV2_OUTPUT_SIZE][CONV2_OUTPUT_SIZE];
float out[POOL2_CHANNELS][POOL2_OUTPUT_SIZE][POOL2_OUTPUT_SIZE];
  Max_Pooling_1(image,POOL_STRIDE,out);
   cout<<"--------------------------------"<<endl;
  cout<<"Max Pooling Layer Results"<<endl;
  for(int k=0;k<CONV2_OUTPUT_CHANNELS;k++)
{
cout<<endl;
cout<<"output max pooling channel "<<k+1<< ".\n";
cout<<endl;
for(int i=0;i<=(CONV2_OUTPUT_SIZE/2)-1;i++)// print the output
{
	cout<<"\n";
	for(int j=0;j<=(CONV2_OUTPUT_SIZE/2)-1;j++)
	{
		cout<<out[k][i][j]<<" ";
		
	}
}
cout<<endl;
}
	cout<<"--------------------------------"<<endl;
return 0;
}
