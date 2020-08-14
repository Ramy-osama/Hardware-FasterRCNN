//============================================================================
// Name        : fc1.cpp
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
#define image_channels                              1


#define kernel_biases                       2

int x;
static int y=1;
int s[image_channels*image_row*image_column]={0};

void fc ( int conv_op[image_channels][image_row][image_column],
		    int bias[image_channels*image_row*image_column],
			int filter[image_channels*image_row*image_column],
			int new_nodes[image_channels*image_row*image_column]
			)
			{


	if(y!=0)
	{
	int k=0;
	int flattened[image_channels*image_row*image_column]={0};
	for(int c=0;c<image_channels;c++)
	for(int i=0;i<image_row;i++)
	for(int j=0;j<image_column;j++){
	flattened[k]=conv_op[c][i][j];
	k++;
	}
	y=0;





		     for(int i=0;i<image_channels*image_row*image_column;i++)
		     {
		     s[i]=flattened[i]*filter[i]+bias[i];
		     }
	}

	if(y==0)
	{

				     for(int i=0;i<image_channels*image_row*image_column;i++)
				     s[i]=s[i]*new_nodes[i]+bias[i];
	}





	 }


