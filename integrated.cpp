#include <iostream>
#include<stdio.h>
#include <math.h>
#define image_size 4
#define image_channels 3 
#define kernel_size 3 
#define kernel_channels image_channels 
#define kernel_filters 2
#define kernel_biases kernel_filters 
#define conv_op_size image_size-kernel_size+1
#define conv_op_channels kernel_filters   
using namespace std;
//Softmax 
void softmax(float s[(conv_op_size/2)*(conv_op_size/2)*(conv_op_channels)])
{
	float sum=0;
	for (int i=0;i<(conv_op_size/2)*(conv_op_size/2)*(conv_op_channels);i++)
	{
		sum+=expf(s[i]);
		
	}
	for (int i=0;i<(conv_op_size/2)*(conv_op_size/2)*(conv_op_channels);i++)
	{
		s[i]=(expf(s[i]))/sum;
	}
}
//fully connected layer
void fc ( float flattened[(conv_op_size/2)*(conv_op_size/2)*(conv_op_channels)],
		    float bias[(conv_op_size/2)*(conv_op_size/2)*(conv_op_channels)],
			float filter[(conv_op_size/2)*(conv_op_size/2)*(conv_op_channels)],float s[(conv_op_size/2)*(conv_op_size/2)*(conv_op_channels)]
			
			)
			{
		     for(int i=0;i<(conv_op_size/2)*(conv_op_size/2)*(conv_op_channels);i++)
		     {
		     s[i]=flattened[i]*filter[i]+bias[i];
		     }
			}
//Rectified linear unit 
int relu(int a)
{
    return a > 0 ? a : 0;
}
//Convlutional layer
void convo ( int input_image[image_channels][image_size][image_size],
			int kernel[kernel_filters][kernel_channels][kernel_size][kernel_size],
			int bias[kernel_biases],
			int conv_op[conv_op_channels][conv_op_size][conv_op_size])
			{
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
							 mul= kernel[filters][kchan][krow][kcol] * input_image[kchan][irow][icol];
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

				
				conv_op[c][i][j]= relu( sum+ bias[c]); 
		 }
	 }
}
				
			}
//Max Pooling layer
void Max_Pooling(int image[conv_op_channels][conv_op_size][conv_op_size] ,int stride,int out[conv_op_channels][conv_op_size/2][conv_op_size/2])
{
int r1=0; // rows of output matrix
int c1=0; // columns of output matrix
// using 2x2 sub-window to compute the output
	for (int k=0;k<conv_op_channels;k=k+1)
	{
		r1=0;
		c1=0;
	
for (int i=0;i<=(conv_op_size-2);i=i+stride)
{
	for(int j=0;j<=(conv_op_size-2);j=j+stride)
	{
	
		
		if((image[k][i][j]>=image[k+1][i][j])&&(image[k][i][j]>=image[k][i+1][j])&&(image[k][i][j]>=image[k+1][i+1][j]))
        {
        	out[k][r1][c1]=image[k][i][j];
        	c1++;
        		if ((c1==(conv_op_size/2)) && (r1<((conv_op_size/2)-1)))
        		{
        			c1=0;
        			r1++;
				}
        
        continue;
		}
else if ((image[k+1][i][j]>=image[k][i][j])&&(image[k+1][i][j]>=image[k][i+1][j])&&(image[k+1][i][j]>=image[k+1][i+1][j]))
 {
 	out[k][r1][c1]=image[k+1][i][j];
        	c1++;
        		if ((c1==(conv_op_size/2)) && (r1<((conv_op_size/2)-1)))
        		{
        			c1=0;
        			r1++;
				}
        
        	continue;
		}

else if((image[k][i+1][j]>=image[k+1][i][j])&&(image[k][i+1][j]>=image[k][i][j])&&(image[k][i+1][j]>=image[k+1][i+1][j])) 
 {
 		out[k][r1][c1]=image[k][i+1][j];
        	c1++;
        		if ((c1==(conv_op_size/2)) && (r1<((conv_op_size/2)-1)))
        		{
        			c1=0;
        			r1++;
				}
        
        continue;
		}

else if((image[k+1][i+1][j]>=image[k][i][j])&&(image[k+1][i+1][j]>=image[k][i+1][j])&&(image[k+1][i+1][j]>=image[k+1][i][j])) 
 {
 		out[k][r1][c1]=image[k+1][i+1][j];
        	c1++;
        			if ((c1==(conv_op_size/2)) && (r1<((conv_op_size/2)-1)))
        		{
        			c1=0;
        			r1++;
				}
        
        continue;
		}

	}
}
}
}
int main() {
//Default stride is 2 
int stride=2;
int  ip_img [image_channels][image_size][image_size] = { {  { 1, 2, 3,0 }, {5,2,1,3}, {0,4,2,1},{0,0,0,0} }, { {0,2,5,3}, {9,0,6,1}, {7,5,2,5},{0,0,0,0} } , { {3,2,0,1}, {7,2,3,5},{0,6,2,1},{0,0,0,0}} };
	int  conv_kernels [kernel_filters][kernel_channels][kernel_size][kernel_size] ={ { {  { 0, 1, 5 }, {2, 1, 0}, {3, 5, 9} }, { {7, 6, 0}, {2, 0, 3}, {4, 2, 1} } , { {3, 2, 1}, {0, 6, 7}, {5, 6, 0} } }, { {  { 3 , 7, 1 }, {9, 0, 2}, {5, 6, 3} }, { {5, 2, 1}, {3, 6, 0}, {2, 1, 4} } , { {0, 5, 1}, {3, 7, 4}, {6, 2, 0} } } };
	int  kernel_bias [kernel_biases]= {1,2};// bias of convlution layer
	int  res[conv_op_channels][conv_op_size][conv_op_size];// output of the convlutional layer
int out[conv_op_channels][conv_op_size/2][conv_op_size/2]; // output of the max pooling layer
	
cout << "input_image matconv_op_channelsix "<< endl;
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
		cout<<"--------------------------------"<<endl;
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
	cout<<"--------------------------------"<<endl;
convo (ip_img,conv_kernels,kernel_bias,res);
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

  Max_Pooling(res,stride,out);
  cout<<"--------------------------------"<<endl;
  cout<<"Max Pooling Layer Results"<<endl;
  for(int k=0;k<conv_op_channels;k++)
{
cout<<endl;
cout<<"output max pooling channel "<<k+1<< ".\n";
cout<<endl;
for(int i=0;i<=(conv_op_size/2)-1;i++)// print the output
{
	cout<<"\n";
	for(int j=0;j<=(conv_op_size/2)-1;j++)
	{
		cout<<out[k][i][j]<<" ";
		
	}
}
cout<<endl;
}
	cout<<"--------------------------------"<<endl;
	int f=0;
		float flattened[(conv_op_size/2)*(conv_op_size/2)*(conv_op_channels)]={0};
		for(int c=0;c<conv_op_channels;c++)
		for(int i=0;i<conv_op_size;i++)
		for(int j=0;j<conv_op_size;j++){
		flattened[f]=out[c][i][j];
		f++;
		}
		float bias[(conv_op_size/2)*(conv_op_size/2)*(conv_op_channels)]={0.1,0.2};//bias of fully connected layer
		float filter[(conv_op_size/2)*(conv_op_size/2)*(conv_op_channels)]={0.01,0.02};//filter of fully connected layer
		float s[(conv_op_size/2)*(conv_op_size/2)*(conv_op_channels)]={};//output of the fully connected layer
				    fc(flattened,bias,filter,s);
				    cout<<"Fully Connected Layer Results"<<endl;
				    for(int i=0;i<(conv_op_size/2)*(conv_op_size/2)*(conv_op_channels);i++)
				    {
				    	cout<<"fully connected "<<i+1<<endl;
				    	cout<<s[i]<<"\n";
					}
					softmax(s);//passing the output of the fully connected layer to the softmax layer
	cout<<"--------------------------------"<<endl;
	cout<<"Softmax results"<<"\n";
for (int i=0;i<(conv_op_size/2)*(conv_op_size/2)*(conv_op_channels);i++)
{
	cout<<s[i];
	cout<<endl;
}

float max=0;
for (int i=0;i<(conv_op_size/2)*(conv_op_size/2)*(conv_op_channels);i++)
{
	for(int j=0;j<(conv_op_size/2)*(conv_op_size/2)*(conv_op_channels);j++)
	{
		if(s[i]>=s[j])
		{
			max=s[i];
		}
	}
}
cout<<"--------------------------------"<<endl;
cout<<"Classification"<<endl;
cout<<"max is "<<max<<endl;
return 0;
}
