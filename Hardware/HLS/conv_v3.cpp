/*this version handels conv for number of filters on the same image 
Author : Rofida
*/

#include <iostream>
#include <stdlib.h>     
#include <time.h>
using namespace std;

#define image_size 5 //final size = 5*5=25
#define kernel_size 3 
#define filters 3
#define conv_op_size image_size-kernel_size+1
#define conv_op_channels 3

int convo ( int input_image[image_size][image_size],
			int kernel[kernel_size][kernel_size][filters],
			int conv_op[conv_op_size][conv_op_size][conv_op_channels]) {
			    
for (int c=0; c< conv_op_channels ;c++){
	 
	   for (int i=0; i< conv_op_size; i++){
		 for (int j=0; j< conv_op_size; j++){
		     int irow= i;
		     int  icol= j;
		     int sum=0;
		     int mul; 
		    
			     	
					 for (int krow=0; krow<kernel_size ; krow++){
						 for (int kcol=0; kcol<kernel_size ;kcol++){
							
						
							 mul= kernel[krow][kcol][c]*input_image[irow][icol];
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
            conv_op[i][j][c]= sum;					 
		 }	 
	 }
   }
}
			



int main()
{
    int x [image_size][image_size]= {{1,2,3,4,5},{0,2,3,0,5},{1,2,0,4,5},{9,3,3,0,5},{3,2,0,4,1}};
	int y [kernel_size][kernel_size][filters]= { {{0,1,2},{2,3,1},{0,4,0}}, {{5,6,1},{3,4,0},{3,0,4}} , {{1,5,6},{3,1,7},{8,2,0}}  };
	int res[conv_op_size][conv_op_size][conv_op_channels];
	
	//srand (time(NULL));
	 
    /*for( int i = 0; i < image_size; ++i)
	{
		for( int j = 0;  j < image_size ; ++j)
		{
		x[i][j] = rand()%50;
		}
	}
	
	/*for( int i = 0; i < kernel_size; ++i)
	{
		for( int j = 0;  j < kernel_size ; ++j)
		{
		y[i][j] = rand()%50;
		}
	} */ 
    
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
	
	cout <<endl<<endl<<"Kernel matrix:"<< endl<<endl;
	for( int c = 0 ; c  < filters;  c++){
		cout<< "kernel filter" << c+1 <<endl;
	for( int a = 0 ; a < kernel_size;  a++)
	{
		for (int b = 0 ; b < kernel_size ; b++)
		{   
			
				cout<<y[a][b][c];
				cout<<" ";
			}
			cout <<endl;
	}
	}
	
	convo (x,y,res);
	cout << endl<<"conv_op matrix: "<< endl<<endl;
	for( int c = 0 ; c< conv_op_size;  c++){
		cout<< "output channel" << c+1 <<endl;
	for( int a = 0 ; a< conv_op_size;  a++)
	{
		for (int b = 0 ; b < conv_op_size ; b++)
		{   
			
				cout<<res[a][b][c];
				cout<<" ";
			}
			cout <<endl;
	}
	
	}
	
}
