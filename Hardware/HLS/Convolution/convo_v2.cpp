#include <iostream>
#include <stdlib.h>     
#include <time.h>
using namespace std;

#define image_size 5 //final size = 5*5=25
#define kernel_size 3 
#define conv_op_size image_size-kernel_size+1

int convo ( int input_image[image_size][image_size],
			int kernel[kernel_size][kernel_size],
			int conv_op[conv_op_size][conv_op_size]){
			    
	 
	 for (int i=0; i< conv_op_size; i++){
		 for (int j=0; j< conv_op_size; j++){
		     int irow= i;
		     int  icol= j;
		     int sum=0;
		     int mul;
					 for (int krow=0; krow<kernel_size ; krow++){
						 for (int kcol=0; kcol<kernel_size ;kcol++){
						     
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
		 }
	 }
}


int main()
{
    int x [image_size][image_size];       //= {{1,2,3,4,5},{0,2,3,0,5},{1,2,0,4,5},{9,3,3,0,5},{3,2,0,4,1}};
	int y [kernel_size][kernel_size];     //={{1,2,3},{4,5,0},{0,8,9}};
	int res[conv_op_size][conv_op_size];
	
	srand (time(NULL));
	 
    for( int i = 0; i < image_size; ++i)
	{
		for( int j = 0;  j < image_size ; ++j)
		{
		x[i][j] = rand()%50;
		}
	}
	
	for( int i = 0; i < kernel_size; ++i)
	{
		for( int j = 0;  j < kernel_size ; ++j)
		{
		y[i][j] = rand()%50;
		}
	} 
    
    cout << "input_image matrix "<< endl;
	for( int a = 0 ; a< image_size;  a++)
	{
		for (int b = 0 ; b < image_size ; b++)
		{   
			
				cout<<x[a][b];
				cout<<" ";
			}
			cout <<endl;
	}
	
	cout << "Kernel matrix "<< endl;
	for( int a = 0 ; a< kernel_size;  a++)
	{
		for (int b = 0 ; b < kernel_size ; b++)
		{   
			
				cout<<y[a][b];
				cout<<" ";
			}
			cout <<endl;
	}
	
	convo (x,y,res);
	cout << "conv_op matrix "<< endl;
	for( int a = 0 ; a< conv_op_size;  a++)
	{
		for (int b = 0 ; b < conv_op_size ; b++)
		{   
			
				cout<<res[a][b];
				cout<<" ";
			}
			cout <<endl;
	}
	
}



