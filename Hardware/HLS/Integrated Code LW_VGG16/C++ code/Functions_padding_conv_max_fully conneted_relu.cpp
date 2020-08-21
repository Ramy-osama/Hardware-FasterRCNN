#include"defines.h"
#include <iostream>
#include <math.h>
void matrixpadding_0(
	float matrix_input[L1_IMAGE_CHANNELS][L1_UNPADDED][L1_UNPADDED],
	float matrix_paded[L1_IMAGE_CHANNELS][L1_PADDED ][L1_PADDED ]
)	
{
	std:: cout<<"start of the function padding 0\n";
	for( int f = 0 ; f <L1_IMAGE_CHANNELS;  f++)
	{
	  for( int i = L1_PAD_SIZE,m=0 ; i < (L1_PADDED )-L1_PAD_SIZE;  i++,m++)
	   {
		for (int j = L1_PAD_SIZE,n=0; j <(L1_PADDED )-L1_PAD_SIZE ; j++,n++)
		{

			
				matrix_paded[f][i][j] = matrix_input[f][m][n];
		}
	  }
	}
	std:: cout<<"end of function padding 0\n";
}
void matrixpadding_1(
	float matrix_input[L0_IMAGE_CHANNELS][L0_UNPADDED][L0_UNPADDED],
	float matrix_paded[L0_IMAGE_CHANNELS][L0_PADDED ][L0_PADDED ]
)	
{
	for( int f = 0 ; f <CONV1_OUTPUT_CHANNELS;  f++)
	{
	  for( int i = L0_PAD_SIZE ,m=0 ; i < (L1_PADDED )-L0_PAD_SIZE ;  i++,m++)
	   {
		for (int j = L0_PAD_SIZE ,n=0; j <(L1_PADDED )-L0_PAD_SIZE  ; j++,n++)
		{

			
				matrix_paded[f][i][j] = matrix_input[f][m][n];
		}
	  }
	}
}
void matrixpadding_2(
	float matrix_input[L2_FMAP_CHANNELS ][L2_UNPADDED ][L2_UNPADDED ],
	float matrix_paded[L2_FMAP_CHANNELS ][L2_PADDED ][L2_PADDED ]
)	
{
	for( int f = 0 ; f <CONV1_OUTPUT_CHANNELS;  f++)
	{
	  for( int i = L2_PAD_SIZE,m=0 ; i < (L2_PADDED )-L2_PAD_SIZE;  i++,m++)
	   {
		for (int j = L2_PAD_SIZE,n=0; j <(L2_PADDED )-L2_PAD_SIZE ; j++,n++)
		{
			
				matrix_paded[f][i][j] = matrix_input[f][m][n];
		}
	  }
	}
}

float relu(float a)
{
    return a > 0 ? a : 0;
}

void conv_0 ( float input_image[L1_IMAGE_CHANNELS][L1_PADDED][L1_PADDED],
			float kernel[CONV1_1_FILTERS_NUMBERS][CONV1_1_KERNEL_CHANNELS][CONV1_1_KERNEL_SIZE][CONV1_1_KERNEL_SIZE],
			float bias[CONV1_1_FILTERS_NUMBERS],
			float conv_op[CONV1_OUTPUT_CHANNELS][CONV1_OUTPUT_SIZE][CONV1_OUTPUT_SIZE])
			{

for	(int c =0; c< CONV1_OUTPUT_CHANNELS; c++){
	 int filters = c;

	 for (int i=0; i< CONV1_OUTPUT_SIZE; i++){

		 for (int j=0; j< CONV1_OUTPUT_SIZE; j++){
			 int irow= i;
		     int  icol= j;
		     float sum=0;
		     float mul;

				for (int kchan=0 ;kchan< CONV1_1_KERNEL_CHANNELS; kchan++){
					irow= i;
		            icol= j;

					 for (int krow=0; krow<CONV1_1_KERNEL_SIZE ; krow++){

						  for (int kcol=0; kcol<CONV1_1_KERNEL_SIZE ;kcol++){
							 mul= kernel[filters][kchan][krow][kcol] * input_image[kchan][irow][icol];
							 sum += mul;
							 if(icol == (j+CONV1_1_KERNEL_SIZE-1)){
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
			
			
			
			
void conv_1 ( float input_image[CONV1_OUTPUT_CHANNELS][L1_PADDED][L1_PADDED],
			float kernel[CONV1_2_FILTERS_NUMBERS][CONV1_2_KERNEL_CHANNELS][CONV1_2_KERNEL_SIZE][CONV1_2_KERNEL_SIZE],
			float bias[CONV1_1_FILTERS_NUMBERS],
			float conv_op[CONV1_OUTPUT_CHANNELS][CONV1_OUTPUT_SIZE][CONV1_OUTPUT_SIZE])
			{

for	(int c =0; c< CONV1_OUTPUT_CHANNELS; c++){
	 int filters = c;

	 for (int i=0; i< CONV1_OUTPUT_SIZE; i++){

		 for (int j=0; j< CONV1_OUTPUT_SIZE; j++){
			 int irow= i;
		     int  icol= j;
		     float sum=0;
		     float mul;

				for (int kchan=0 ;kchan< CONV1_2_KERNEL_CHANNELS; kchan++){
					irow= i;
		            icol= j;

					 for (int krow=0; krow<CONV1_2_KERNEL_SIZE ; krow++){

						  for (int kcol=0; kcol<CONV1_2_KERNEL_SIZE ;kcol++){
							 mul= kernel[filters][kchan][krow][kcol] * input_image[kchan][irow][icol];
							 sum += mul;
							 if(icol == (j+CONV1_2_KERNEL_SIZE-1)){
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

void conv_2 ( float input_image[L2_FMAP_CHANNELS][L2_PADDED][L2_PADDED],
			float kernel[CONV2_1_FILTERS_NUMBERS][CONV2_1_KERNEL_CHANNELS][CONV2_1_KERNEL_SIZE][CONV2_1_KERNEL_SIZE],
			float bias[CONV2_1_FILTERS_NUMBERS],
			float conv_op[CONV2_OUTPUT_CHANNELS][CONV2_OUTPUT_SIZE][CONV2_OUTPUT_SIZE])
			{

for	(int c =0; c< CONV2_OUTPUT_CHANNELS; c++){
	 int filters = c;

	 for (int i=0; i< CONV2_OUTPUT_SIZE; i++){

		 for (int j=0; j< CONV2_OUTPUT_SIZE; j++){
			 int irow= i;
		     int  icol= j;
		     float sum=0;
		     float mul;

				for (int kchan=0 ;kchan< CONV2_1_KERNEL_CHANNELS; kchan++){
					irow= i;
		            icol= j;

					 for (int krow=0; krow<CONV2_1_KERNEL_SIZE ; krow++){

						  for (int kcol=0; kcol<CONV2_1_KERNEL_SIZE ;kcol++){
							 mul= kernel[filters][kchan][krow][kcol] * input_image[kchan][irow][icol];
							 sum += mul;
							 if(icol == (j+CONV2_1_KERNEL_SIZE-1)){
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
			
			void Max_Pooling_1(float image[CONV1_OUTPUT_CHANNELS ][CONV1_OUTPUT_SIZE][CONV1_OUTPUT_SIZE] ,int POOL_STRIDE,float out[POOL1_CHANNELS][POOL1_OUTPUT_SIZE][POOL1_OUTPUT_SIZE])
{
int r1=0; // rows of output matrix
int c1=0; // columns of output matrix
// using 2x2 sub-window to compute the output
	for (int k=0;k<CONV1_OUTPUT_CHANNELS;k=k+1)
	{
		r1=0;
		c1=0;
	
for (int i=0;i<=(CONV1_OUTPUT_SIZE-2);i=i+POOL_STRIDE)
{
	for(int j=0;j<=(CONV1_OUTPUT_SIZE-2);j=j+POOL_STRIDE)
	{
	
		
		if((image[k][i][j]>=image[k+1][i][j])&&(image[k][i][j]>=image[k][i+1][j])&&(image[k][i][j]>=image[k+1][i+1][j]))
        {
        	out[k][r1][c1]=image[k][i][j];
        	c1++;
        		if ((c1==(CONV1_OUTPUT_SIZE/2)) && (r1<((CONV1_OUTPUT_SIZE/2)-1)))
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
        		if ((c1==(CONV1_OUTPUT_SIZE/2)) && (r1<((CONV1_OUTPUT_SIZE/2)-1)))
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
        		if ((c1==(CONV1_OUTPUT_SIZE/2)) && (r1<((CONV1_OUTPUT_SIZE/2)-1)))
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
        			if ((c1==(CONV1_OUTPUT_SIZE/2)) && (r1<((CONV1_OUTPUT_SIZE/2)-1)))
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
void Max_Pooling_2(float image[CONV2_OUTPUT_CHANNELS ][CONV2_OUTPUT_SIZE][CONV2_OUTPUT_SIZE] ,int POOL_STRIDE,float out[POOL2_CHANNELS][POOL2_OUTPUT_SIZE][POOL2_OUTPUT_SIZE])
{
int r1=0; // rows of output matrix
int c1=0; // columns of output matrix
// using 2x2 sub-window to compute the output
	for (int k=0;k<CONV2_OUTPUT_CHANNELS;k=k+1)
	{
		r1=0;
		c1=0;
	
for (int i=0;i<=(CONV2_OUTPUT_SIZE-2);i=i+POOL_STRIDE)
{
	for(int j=0;j<=(CONV2_OUTPUT_SIZE-2);j=j+POOL_STRIDE)
	{
	
		
		if((image[k][i][j]>=image[k+1][i][j])&&(image[k][i][j]>=image[k][i+1][j])&&(image[k][i][j]>=image[k+1][i+1][j]))
        {
        	out[k][r1][c1]=image[k][i][j];
        	c1++;
        		if ((c1==(CONV2_OUTPUT_SIZE/2)) && (r1<((CONV2_OUTPUT_SIZE/2)-1)))
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
        		if ((c1==(CONV2_OUTPUT_SIZE/2)) && (r1<((CONV2_OUTPUT_SIZE/2)-1)))
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
        		if ((c1==(CONV2_OUTPUT_SIZE/2)) && (r1<((CONV2_OUTPUT_SIZE/2)-1)))
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
        			if ((c1==(CONV2_OUTPUT_SIZE/2)) && (r1<((CONV2_OUTPUT_SIZE/2)-1)))
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

void fc1 ( float flattened[Flatened_SIZE],
		    float bias[outputsizefc1],
			float filter[Flatened_SIZE][outputsizefc1],
			float Fc_output[outputsizefc1]   )
			{

		         for(int i=0;i<outputsizefc1;i++)
		     {
		             for(int j=0;j<Flatened_SIZE;j++)
		             {
		             	            Fc_output[i]=Fc_output[i]+flattened[j]*filter[j][i];

		             	             }
		             	             Fc_output[i]=relu(Fc_output[i]+bias[i]);
		     }
			}


void fc2 ( float flattened[outputsizefc1],
		    float bias[outputsizefc1],
			float filter[outputsizefc1][outputsizefc1],
			float Fc_output[outputsizefc1]

			)
			{

		         for(int i=0;i<outputsizefc1;i++)
		     {
		             for(int j=0;j<outputsizefc1;j++)
		             {
		             	            Fc_output[i]=Fc_output[i]+flattened[j]*filter[j][i];

		             	             }
		             	             Fc_output[i]=relu(Fc_output[i]+bias[i]);
		     }
			}
void fc3 ( float flattened[outputsizefc1],
		    float bias[Last_Layer],
			float filter[outputsizefc1][Last_Layer],
			float Fc_output[Last_Layer]

			)
			{

		         for(int i=0;i<Last_Layer;i++)
		     {
		             for(int j=0;j<outputsizefc1;j++)
		             {
		             	            Fc_output[i]=Fc_output[i]+flattened[j]*filter[j][i];

		             	             }
		             	             Fc_output[i]=Fc_output[i]+bias[i];
		     }
			}
void softmax(float arr[Last_Layer])
{
	float sum=0;
	for (int i=0;i<Last_Layer;i++)
	{
		sum+=arr[i];
		
	}
	for (int i=0;i<Last_Layer;i++)
	{
		arr[i]=arr[i]/sum;
	}
}
void flattening_1 ( float conv_op[POOL2_CHANNELS][POOL2_OUTPUT_SIZE][POOL2_OUTPUT_SIZE],
                  float flattened[POOL2_CHANNELS*POOL2_OUTPUT_SIZE*POOL2_OUTPUT_SIZE])
{

	      int k=0;
		for(int c=0;c<POOL2_CHANNELS;c++)
		for(int i=0;i<POOL2_OUTPUT_SIZE;i++)
		for(int j=0;j<POOL2_OUTPUT_SIZE;j++){
		flattened[k]=conv_op[c][i][j];
		k++;
		}
}
