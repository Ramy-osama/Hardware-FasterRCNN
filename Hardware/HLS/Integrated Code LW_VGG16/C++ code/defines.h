/******************************************************************************
 * this H File contains the hyper params of the VGG16 Nueral Netwrok.
 *
 * NOTES ON THE VGG16 ARCHITECTURE:
 * 1) All of the filters are the same size (3x3).
 * 2) All of the windows of the maxpooling function are the same size (2x2) and all the stride=2.
 *
 *
 *
 *******************************************************************************/
 
#ifndef defines
#define L1_UNPADDED                            28
#define L1_PAD_SIZE                            1
#define L1_PADDED                              L1_UNPADDED+(2*L1_PAD_SIZE)
#define L1_IMAGE_SIZE 			               L1_PADDED
#define L1_IMAGE_CHANNELS		               1
                          
#define CONV1_1_KERNEL_SIZE 	               3
#define CONV1_1_KERNEL_CHANNELS                L1_IMAGE_CHANNELS	
#define CONV1_1_FILTERS_NUMBERS                64
#define CONV1_1_BIAS_SIZE                      CONV1_1_FILTERS_NUMBERS

#define CONV1_2_KERNEL_SIZE 	               3
#define CONV1_2_KERNEL_CHANNELS                CONV1_1_FILTERS_NUMBERS	
#define CONV1_2_FILTERS_NUMBERS                64
#define CONV1_2_BIAS_SIZE                      CONV1_2_FILTERS_NUMBERS

#define CONV1_3_KERNEL_SIZE 	               3
#define CONV1_3_KERNEL_CHANNELS                CONV1_2_FILTERS_NUMBERS	
#define CONV1_3_FILTERS_NUMBERS                64
#define CONV1_3_BIAS_SIZE                      CONV1_3_FILTERS_NUMBERS

#define CONV1_4_KERNEL_SIZE 	               3
#define CONV1_4_KERNEL_CHANNELS                CONV1_3_FILTERS_NUMBERS	
#define CONV1_4_FILTERS_NUMBERS                64
#define CONV1_4_BIAS_SIZE                      CONV1_4_FILTERS_NUMBERS


#define CONV1_OUTPUT_SIZE                      L1_IMAGE_SIZE - CONV1_4_KERNEL_SIZE + 1
#define CONV1_OUTPUT_CHANNELS                  CONV1_4_FILTERS_NUMBERS

#define POOL1_INPUT_SIZE                       CONV1_OUTPUT_SIZE
#define POOL1_CHANNELS                         CONV1_OUTPUT_CHANNELS
#define POOL1_OUTPUT_SIZE                      POOL1_INPUT_SIZE/2

#define L2_UNPADDED                            POOL1_OUTPUT_SIZE
#define L2_PAD_SIZE                            1
#define L2_PADDED                              L2_UNPADDED+(2*L2_PAD_SIZE)
#define L2_FMAP_SIZE 			               L2_PADDED
#define L2_FMAP_CHANNELS		               POOL1_CHANNELS

#define CONV2_1_KERNEL_SIZE 	               3
#define CONV2_1_KERNEL_CHANNELS                L2_FMAP_CHANNELS	
#define CONV2_1_FILTERS_NUMBERS                64
#define CONV2_1_BIAS_SIZE                      CONV2_1_FILTERS_NUMBERS

#define CONV2_2_KERNEL_SIZE 	               3
#define CONV2_2_KERNEL_CHANNELS                CONV2_1_FILTERS_NUMBERS	
#define CONV2_2_FILTERS_NUMBERS                64
#define CONV2_2_BIAS_SIZE                      CONV2_2_FILTERS_NUMBERS

#define CONV2_OUTPUT_SIZE                      L2_FMAP_SIZE - CONV2_2_KERNEL_SIZE + 1
#define CONV2_OUTPUT_CHANNELS                  CONV2_2_FILTERS_NUMBERS

#define POOL2_INPUT_SIZE                       CONV2_OUTPUT_SIZE  
#define POOL2_CHANNELS                         CONV2_OUTPUT_CHANNELS  
#define POOL2_OUTPUT_SIZE                      POOL2_INPUT_SIZE/2


#define Flatened_SIZE                          POOL2_OUTPUT_SIZE/2 *POOL2_OUTPUT_SIZE * POOL2_CHANNELS
#define outputsizefc1                          1024

#define L0_UNPADDED                            CONV1_OUTPUT_SIZE
#define L0_PAD_SIZE                            1
#define L0_PADDED                              L0_UNPADDED+(2*L0_PAD_SIZE)
#define L0_IMAGE_SIZE 			               L1_PADDED
#define L0_IMAGE_CHANNELS		               CONV1_OUTPUT_CHANNELS


#define Last_Layer                             10
#endif
	void conv_0 ( float input_image[L1_IMAGE_CHANNELS][L1_PADDED][L1_PADDED],
			float kernel[CONV1_1_FILTERS_NUMBERS][CONV1_1_KERNEL_CHANNELS][CONV1_1_KERNEL_SIZE][CONV1_1_KERNEL_SIZE],
			float bias[CONV1_1_FILTERS_NUMBERS],
			float conv_op[CONV1_OUTPUT_CHANNELS][CONV1_OUTPUT_SIZE][CONV1_OUTPUT_SIZE]);
			
	void conv_1 ( float input_image[CONV1_OUTPUT_CHANNELS][L1_PADDED][L1_PADDED],
			float kernel[CONV1_2_FILTERS_NUMBERS][CONV1_2_KERNEL_CHANNELS][CONV1_2_KERNEL_SIZE][CONV1_2_KERNEL_SIZE],
			float bias[CONV1_1_FILTERS_NUMBERS],
			float conv_op[CONV1_OUTPUT_CHANNELS][CONV1_OUTPUT_SIZE][CONV1_OUTPUT_SIZE]);
			
			
	void conv_1 ( float input_image[CONV1_OUTPUT_CHANNELS][L1_PADDED][L1_PADDED],
			float kernel[CONV1_3_FILTERS_NUMBERS][CONV1_3_KERNEL_CHANNELS][CONV1_3_KERNEL_SIZE][CONV1_3_KERNEL_SIZE],
			float bias[CONV1_1_FILTERS_NUMBERS],
			float conv_op[CONV1_OUTPUT_CHANNELS][CONV1_OUTPUT_SIZE][CONV1_OUTPUT_SIZE]);
			
			
			
	void conv_1 ( float input_image[CONV1_OUTPUT_CHANNELS][L1_PADDED][L1_PADDED],
			float kernel[CONV1_4_FILTERS_NUMBERS][CONV1_4_KERNEL_CHANNELS][CONV1_4_KERNEL_SIZE][CONV1_4_KERNEL_SIZE],
			float bias[CONV1_1_FILTERS_NUMBERS],
			float conv_op[CONV1_OUTPUT_CHANNELS][CONV1_OUTPUT_SIZE][CONV1_OUTPUT_SIZE]);
			
			
	void conv_2 ( float input_image[L2_FMAP_CHANNELS][L2_PADDED][L2_PADDED],
	float kernel[CONV2_1_FILTERS_NUMBERS][CONV2_1_KERNEL_CHANNELS][CONV2_1_KERNEL_SIZE][CONV2_1_KERNEL_SIZE],
	float bias[CONV2_1_FILTERS_NUMBERS],
			float conv_op[CONV2_OUTPUT_CHANNELS][CONV2_OUTPUT_SIZE][CONV2_OUTPUT_SIZE]);
			
			
	void conv_2 ( float input_image[CONV2_OUTPUT_CHANNELS][CONV2_OUTPUT_SIZE][CONV2_OUTPUT_SIZE],
			float kernel[CONV2_2_FILTERS_NUMBERS][CONV2_2_KERNEL_CHANNELS][CONV2_2_KERNEL_SIZE][CONV2_2_KERNEL_SIZE],
			float bias[CONV2_2_FILTERS_NUMBERS],
			float conv_op[CONV2_OUTPUT_CHANNELS][CONV2_OUTPUT_SIZE][CONV2_OUTPUT_SIZE]);
			
			void matrixpadding_0(
	float matrix_input[L1_IMAGE_CHANNELS][L1_UNPADDED][L1_UNPADDED],
	float matrix_paded[L1_IMAGE_CHANNELS][L1_PADDED ][L1_PADDED ]
);
void matrixpadding_1(
	float matrix_input[L0_IMAGE_CHANNELS][L0_UNPADDED][L0_UNPADDED],
	float matrix_paded[L0_IMAGE_CHANNELS][L0_PADDED ][L0_PADDED ]
);
void matrixpadding_2(
	float matrix_input[L2_FMAP_CHANNELS ][L2_UNPADDED ][L2_UNPADDED ],
	float matrix_paded[L2_FMAP_CHANNELS ][L2_PADDED ][L2_PADDED ]
);
void Max_Pooling_1(float image[CONV1_OUTPUT_CHANNELS ][CONV1_OUTPUT_SIZE][CONV1_OUTPUT_SIZE] ,int POOL_STRIDE,float out[POOL1_CHANNELS][POOL1_OUTPUT_SIZE][POOL1_OUTPUT_SIZE]);
void Max_Pooling_2(float image[CONV2_OUTPUT_CHANNELS ][CONV2_OUTPUT_SIZE][CONV2_OUTPUT_SIZE] ,int POOL_STRIDE,float out[POOL2_CHANNELS][POOL2_OUTPUT_SIZE][POOL2_OUTPUT_SIZE]);
void softmax(float arr[Last_Layer]);
void fc1 ( float flattened[Flatened_SIZE],
		    float bias[outputsizefc1],
			float filter[Flatened_SIZE][outputsizefc1],
			float Fc_output[outputsizefc1]

			);
		void fc2 ( float flattened[outputsizefc1],
		    float bias[outputsizefc1],
			float filter[outputsizefc1][outputsizefc1],
			float Fc_output[outputsizefc1]

			);
	void fc3 ( float flattened[outputsizefc1],
		    float bias[Last_Layer],
			float filter[outputsizefc1][Last_Layer],
			float Fc_output[Last_Layer]	);		



			


