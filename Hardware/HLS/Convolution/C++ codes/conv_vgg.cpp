#include "defines.h"

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
			
			
			
			
void conv_1 ( float input_image[CONV1_OUTPUT_CHANNELS][CONV1_OUTPUT_SIZE][CONV1_OUTPUT_SIZE],
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
			
			
			