/* 
some of the macros are always equal but I named them with different names to make the code more readable ,
1) this design assumes that always number of channels of the kernel = number of channels of input image  
2) number of filters = number of the channels of the output image
*/
#include <iostream>
#include <stdlib.h>     
#include <time.h>
#include"parampad.h"
using namespace std;




int main()
{
    int x [image_channels][image_size][image_size] = { {  { 1, 2, 3,0 }, {5,2,1,3}, {0,4,2,1},{0,0,0,0} }, { {0,2,5,3}, {9,0,6,1}, {7,5,2,5},{0,0,0,0} } , { {3,2,0,1}, {7,2,3,5},{0,6,2,1},{0,0,0,0}} };
	int a [kernel_filters][kernel_channels][kernel_size][kernel_size] ={ { {  { 0, 1, 5 }, {2, 1, 0}, {3, 5, 9} }, { {7, 6, 0}, {2, 0, 3}, {4, 2, 1} } , { {3, 2, 1}, {0, 6, 7}, {5, 6, 0} } }, { {  { 3 , 7, 1 }, {9, 0, 2}, {5, 6, 3} }, { {5, 2, 1}, {3, 6, 0}, {2, 1, 4} } , { {0, 5, 1}, {3, 7, 4}, {6, 2, 0} } } };
	
	int res[conv_op_channels][conv_op_size][conv_op_size];
	
	
    
    cout << "input_image matrix "<< endl;
	for( int c = 0 ; c  < image_channels;  c++){
		cout<< endl<<"image channel_" << c+1 <<endl;
	for( int a = 0 ; a< image_size;  a++)
	{
		for (int b = 0 ; b < image_size ; b++)
		{   
			
				cout<<x[c][a][b];
				cout<<" ";
			}
			cout <<endl;
	}
	}
	
	cout <<endl<<endl<<endl<<"kernel filters : "<< endl;
	for(int filter_number = 0; filter_number < 2 ; filter_number ++)
{
	
	for(int channel = 0 ; channel <3 ; channel ++)
	{   cout<<endl<<"kernel filter_"<<filter_number+1;
		cout<<endl<<"Kernel channel_"<<channel+1;
		for(int row = 0; row < 3 ; row++)
		{
			cout<<endl;
			for(int col = 0 ; col < 3 ; col++)
			{
				cout<< a[filter_number][channel][row][col]<< "  ";
			}
		}
		cout<<endl;
	}
}
      int out[depthpool][rowpool/2][columnpool/2];
	
	convo (x,a,res,out);
	cout << endl<<endl <<endl<<"convlution output feature maps: "<< endl<<endl;
	for( int c = 0 ; c< conv_op_channels;  c++){
		cout<< "output feature map_" << c+1 <<endl;
	for( int a = 0 ; a< conv_op_size;  a++)
	{
		for (int b = 0 ; b < conv_op_size ; b++)
		{   
			
				cout<<res[c][a][b];
				cout<<" ";
			}
			cout <<endl;
	}
	cout <<endl;
	}
	
	
	cout << endl<<endl <<endl<<"max output feature maps: "<< endl<<endl;
	for( int c = 0 ; c< depthpool;  c++){
		cout<< "output feature map_" << c+1 <<endl;
	for( int a = 0 ; a< rowpool/2;  a++)
	{
		for (int b = 0 ; b < columnpool/2 ; b++)
		{   
			
				cout<<out[c][a][b];
				cout<<" ";
			}
			cout <<endl;
	}
	cout <<endl;
	}
	
	
}