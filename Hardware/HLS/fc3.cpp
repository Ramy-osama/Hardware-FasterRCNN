//============================================================================
// Name        : fc3.cpp
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

	int new_nodes[8]={1,2,3,4,5,6,7,8};
	int bias[8]={};
	int s[image_channels*image_row*image_column]={1,2,3,4,5,6,7,8};
for(int i=0;i<image_channels*image_row*image_column;i++)
s[i]=s[i]*new_nodes[i]+bias[i];

for(int y=0;y<8;y++)
				     			cout<<s[y]<<endl;
}
