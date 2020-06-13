/*************************************************************
 * added to this version :
 * the convolution function now handles adding biases of the convolution filters to get the 
 * final feature map(conv_op) elements 
 * nunmber of biases = number of filters and added after every  3*3*3 convolution operation 
 *
 * some of the macros are always equal but I named them with different names to make the code more readable,
 * 1) number of channels of the kernel = number of channels of input image  
 * 2) number of filters = number of the channels of the output image
 * //////////////////////////////////////////////////////////
 *
 *Author : Rofida Osama
 *
 ***************************************************************/
 
 

#include <iostream>    
using namespace std;

#define image_size                                  4 
#define image_channels                              3 

#define kernel_size                                 3 
#define kernel_channels                     image_channels 
#define kernel_filters                              2
#define kernel_biases                        kernel_filters 

#define conv_op_size                    image_size-kernel_size+1
#define conv_op_channels                    kernel_filters  

void convo ( int input_image[image_channels][image_size][image_size],
			int kernel[kernel_filters][kernel_channels][kernel_size][kernel_size],
			int bias[kernel_biases],
			int conv_op[conv_op_channels][conv_op_size][conv_op_size]);
			    




int main()
{
    int ip_img [image_channels][image_size][image_size] = { {  { 1, 2, 3,0 }, {5,2,1,3}, {0,4,2,1},{0,0,0,0} }, { {0,2,5,3}, {9,0,6,1}, {7,5,2,5},{0,0,0,0} } , { {3,2,0,1}, {7,2,3,5},{0,6,2,1},{0,0,0,0}} };
	int conv_kernels [kernel_filters][kernel_channels][kernel_size][kernel_size] ={ { {  { 0, 1, 5 }, {2, 1, 0}, {3, 5, 9} }, { {7, 6, 0}, {2, 0, 3}, {4, 2, 1} } , { {3, 2, 1}, {0, 6, 7}, {5, 6, 0} } }, { {  { 3 , 7, 1 }, {9, 0, 2}, {5, 6, 3} }, { {5, 2, 1}, {3, 6, 0}, {2, 1, 4} } , { {0, 5, 1}, {3, 7, 4}, {6, 2, 0} } } };
	int kernel_bias [kernel_biases]= {1,2};
	int res[conv_op_channels][conv_op_size][conv_op_size];
	
	
    
    cout << "input_image matrix "<< endl;
	for( int c = 0 ; c  < image_channels;  c++){
		cout<< endl<<"image channel_" << c+1 <<endl;
	for( int a = 0 ; a< image_size;  a++)
	{
		for (int b = 0 ; b < image_size ; b++)
		{   
			
				cout<<ip_img[c][a][b];
				cout<<" ";
		}
			cout <<endl;
	}
	}
	
	cout <<endl<<endl<<endl<<"kernel filters : "<< endl;
	for(int filter_number = 0; filter_number < kernel_filters ; filter_number ++)
{   cout<<endl<<"kernel filter_"<<filter_number+1<<endl;
   cout <<"filter bias_"<< filter_number+1<< " = " << kernel_bias[filter_number]<< endl;
	for(int channel = 0 ; channel < kernel_channels ; channel ++)
	{   
		cout<<endl<<"Kernel channel_"<<channel+1;
		for(int row = 0; row < kernel_size ; row++)
		{
			cout<<endl;
			for(int col = 0 ; col < kernel_size ; col++)
			{
				cout<< conv_kernels[filter_number][channel][row][col]<< "  ";
			}
		}
		cout<<endl;
	}
	
}

}
