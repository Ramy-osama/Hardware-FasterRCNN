//============================================================================
// Name        : fc2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

#define image_size                                  2
#define image_row                                   2
#define image_column                                2
#define image_channels                              2


#define kernel_biases                       2

int main() {
	int k=0;
	int conv_op[2][2][2]={{{1,2},{3,4}},{{5,6},{7,8}}};
		int flattened[image_channels*image_row*image_column]={0};
		for(int c=0;c<image_channels;c++)
		for(int i=0;i<image_row;i++)
		for(int j=0;j<image_column;j++){
		flattened[k]=conv_op[c][i][j];
		k++;
		}
		for(int r=0;r<8;r++)
			cout<<flattened[r]<<endl;
		int bias[8]={};
		int filter[8]={1,2,3,4,5,6,7,8};
		int s[image_channels*image_row*image_column]={};
				     for(int i=0;i<image_channels*image_row*image_column;i++)
				     {
				     s[i]=flattened[i]*filter[i]+bias[i];
				     }
				     for(int y=0;y<8;y++)
				     			cout<<s[y]<<endl;
}
