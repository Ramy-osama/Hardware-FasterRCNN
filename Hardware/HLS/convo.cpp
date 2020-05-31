#include <iostream>
using namespace std;

#define image_size 5 //final size = 4*4=16
#define kernel_size 3 
#define conv_op_size image_size-kernel_size+1

int convo ( int input_image[image_size][image_size],
			int kernel[kernel_size][kernel_size],
			int conv_op[conv_op_size][conv_op_size]){
			    
           //static int sum=0;
           //int mul=0;
	 
	 for (int i=0; i< conv_op_size; i++){
		 for (int j=0; j< conv_op_size; j++){
		     int irow= i;
		     int  icol= j;
		     int sum=0;
		     int mul;
					 for (int krow=0; krow<kernel_size ; krow++){
						 for (int kcol=0; kcol<kernel_size ;kcol++){
						     
						    // int irow= i;
		                    // int  icol= j;
							 mul= kernel[krow][kcol]*input_image[irow][icol];
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
				conv_op[i][j]= sum;
						     sum =0;	 
		 }
	 }
}


int main()
{
    int x [image_size][image_size]={{1,2,3,4,5},{0,2,3,0,5},{1,2,0,4,5},{9,3,3,0,5},{3,2,0,4,1}};
	int y [kernel_size][kernel_size]= {{1,2,3},{4,5,0},{0,8,9}};
	int res[conv_op_size][conv_op_size];
	
	convo (x,y,res);
	for( int a = 0 ; a< conv_op_size;  a++)
	{
		for (int b = 0 ; b < conv_op_size ; b++)
		{
			cout<<res[a][b]<<endl;
		}
	
	}
}



