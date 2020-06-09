/* 
some of the macros are always equal but I named them with different names to make the code more readable ,
1) this design assumes that always number of channels of the kernel = number of channels of input image  
2) number of filters = number of the channels of the output image
*/
#include <iostream>
#include <stdlib.h>     
#include <time.h>
using namespace std;

#define image_size 4 //final size = 4*4=24 elements in every channel
#define image_channels 3 //RGB channels of the input image of the first conv layer
#define kernel_size 3 
#define kernel_channels 3 // every channel of the kernel * every channel of the RGB channels
#define kernel_filters 2
#define conv_op_size image_size-kernel_size+1
#define conv_op_channels 2  //== kernel_filters 

void convo ( int input_image[image_channels][image_size][image_size],
			int kernel[kernel_filters][kernel_channels][kernel_size][kernel_size],
			int conv_op[conv_op_channels][conv_op_size][conv_op_size]){
			    
for	(int c =0; c< conv_op_channels; c++){
	int filters = c;
	 for (int i=0; i< conv_op_size; i++){
		 for (int j=0; j< conv_op_size; j++){
		     int irow= i;
		     int  icol= j;
		     int sum=0;
		     int mul;
			    for (int kchan=0 ;kchan< kernel_channels; kchan++){
					 for (int krow=0; krow<kernel_size ; krow++){
						 for (int kcol=0; kcol<kernel_size ;kcol++){
						     
							 mul= kernel[filters][kchan][krow][kcol] * input_image[kchan][irow][icol];
							 sum += mul;
							 if(icol == (j+kernel_size-1)){
						    	 irow++ ;
								 icol=j; 
							 }
							 else{
								 icol++;
							 }
						 }
					 }
				}	 
				conv_op[c][i][j]= sum;   	 
		 }
	 }
}
			
}
			
			
			
			


int main()
{
    int x [image_channels][image_size][image_size] = { {  { 1, 2, 3,0 }, {5,2,1,3}, {0,4,2,1} }, { {0,2,5,3}, {9,0,6,1}, {7,5,2,5} } , { {3,2,0,1}, {7,2,3,5},{0,6,2,1}}};
	int a [kernel_filters][kernel_channels][kernel_size][kernel_size] ={ { {  { 0, 1, 5 }, {2, 1, 0}, {3, 5, 9} }, { {7, 6, 0}, {2, 0, 3}, {4, 2, 1} } , { {3, 2, 1}, {0, 6, 7}, {5, 6, 0} } }, { {  { 3 , 7, 1 }, {9, 0, 2}, {5, 6, 3} }, { {5, 2, 1}, {3, 6, 0}, {2, 1, 4} } , { {0, 5, 1}, {3, 7, 4}, {6, 2, 0} } } };
 
	
	
    
	
	int res[conv_op_channels][conv_op_size][conv_op_size];
	
	
    
    cout << "input_image matrix "<< endl;
	for( int c = 0 ; c  < image_channels;  c++){
		cout<< "image channel " << c+1 <<endl;
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
	
	cout << endl<<"kernel filters : "<< endl<<endl;
	for(int filter_number = 0; filter_number < 2 ; filter_number ++)
{
	
	for(int channel = 0 ; channel <3 ; channel ++)
	{   cout<<endl<<"kernel filter "<<filter_number+1;
		cout<<endl<<"Kernel channel"<<channel+1;
		for(int row = 0; row < 3 ; row++)
		{
			cout<<endl;
			for(int col = 0 ; col < 3 ; col++)
			{
				cout<< a[filter_number][channel][row][col]<< "  ";
			}
		}
	}
}

	
	convo (x,a,res);
	
	cout << endl<<"conv_op feature map: "<< endl<<endl;
	for( int c = 0 ; c< conv_op_channels;  c++){
		cout<< "output feature map" << c+1 <<endl;
	for( int a = 0 ; a< conv_op_size;  a++)
	{
		for (int b = 0 ; b < conv_op_size ; b++)
		{   
			
				cout<<res[c][a][b];
				cout<<" ";
			}
			cout <<endl;
	}
	
	}
	
}
