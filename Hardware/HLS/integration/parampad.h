#define matrix_dim_input 4
#define number_ofpadding 1
#define Channels         3
#define rowpool 4
#define columnpool 4
#define depthpool 2
#define HW_COSIM
#define image_size 4 //final size = 4*4=24 elements in every channel
#define image_channels 3 //RGB channels of the input image of the first conv layer
#define kernel_size 3 
#define kernel_channels image_channels // every channel of the kernel * every channel of the RGB channels
#define kernel_filters 2
#define conv_op_size image_size-kernel_size+3
#define conv_op_channels kernel_filters  //== kernel_filters
#define stridenumber 2



void matrixpadding(
	int matrix_input[Channels][matrix_dim_input][matrix_dim_input],
	int matrix_paded[Channels][(matrix_dim_input+number_ofpadding*2)][(matrix_dim_input+number_ofpadding*2)]
);	
void convo ( int input_image[image_channels][image_size][image_size],
			int kernel[kernel_filters][kernel_channels][kernel_size][kernel_size],
			int conv_op[conv_op_channels][conv_op_size][conv_op_size],
			int out[depthpool][rowpool/2][columnpool/2]);
			
			
void Max_Pooling(int image[depthpool][rowpool][columnpool] ,int stride,int out[depthpool][rowpool/2][columnpool/2]);