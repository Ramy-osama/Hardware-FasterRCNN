/* 
some of the macros are always equal but I named them with different names to make the code more readable ,
1) this design assumes that always number of channels of the kernel = number of channels of input image  
2) number of filters = number of the channels of the output image
*/
#include <iostream>
#include <stdlib.h>     
#include <time.h>
using namespace std;
#include"parampad.h"
void convo ( int input_image[image_channels][image_size][image_size],
			int kernel[kernel_filters][kernel_channels][kernel_size][kernel_size],
			int conv_op[conv_op_channels][conv_op_size][conv_op_size],
			int out[depthpool][rowpool/2][columnpool/2])
			
			
{
			int matrix_paded[Channels][matrix_dim_input+number_ofpadding*2][matrix_dim_input+number_ofpadding*2]={0};
             matrixpadding(input_image, matrix_paded);
			 
for	(int c =0; c< conv_op_channels; c++){
	int filters = c;
	 for (int i=0; i< conv_op_size; i++){
		 for (int j=0; j< conv_op_size; j++){
		     int irow= i;
		     int  icol= j;
		     int sum=0;
		     int mul;
			    for (int kchan=0 ;kchan< kernel_channels; kchan++){
					
					  int irow= i;
		              int  icol= j;
					 for (int krow=0; krow<kernel_size ; krow++){
						 for (int kcol=0; kcol<kernel_size ;kcol++){
						     
							 mul= kernel[filters][kchan][krow][kcol] * matrix_paded[kchan][irow][icol];
							 sum += mul;
							 if(icol == (j+kernel_size-1)){
						    	 irow++ ;
								 icol=j; 
							 }
							 else {
								 icol++;
							 }
						 }
					 }
				}	 
				conv_op[c][i][j]= sum;   	 
		 }
	 }
}
             
			Max_Pooling(conv_op ,stridenumber,out);
			
			
			
}