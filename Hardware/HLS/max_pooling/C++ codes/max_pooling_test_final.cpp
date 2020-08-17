#include <iostream>
#include<stdio.h>
#include<vector>
#include <stdlib.h> 
#define conv_op_size 6
#define conv_op_channels 3
using namespace std;
void Max_Pooling(float conv_op[conv_op_channels][conv_op_size][conv_op_size] ,int stride,float out[conv_op_channels][conv_op_size/2][conv_op_size/2]);
int main() {
int stride=2;
float conv_op[conv_op_channels][conv_op_size][conv_op_size];
float out[conv_op_channels][conv_op_size/2][conv_op_size/2];

  Max_Pooling(conv_op,stride,out);
   cout<<"--------------------------------"<<endl;
  cout<<"Max Pooling Layer Results"<<endl;
  for(int k=0;k<conv_op_channels;k++)
{
cout<<endl;
cout<<"output max pooling channel "<<k+1<< ".\n";
cout<<endl;
for(int i=0;i<=(conv_op_size/2)-1;i++)// print the output
{
	cout<<"\n";
	for(int j=0;j<=(conv_op_size/2)-1;j++)
	{
		cout<<out[k][i][j]<<" ";
		
	}
}
cout<<endl;
}
	cout<<"--------------------------------"<<endl;
return 0;
}
