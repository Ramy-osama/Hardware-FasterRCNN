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
#define L1_UNPADDED                            224
#define L1_PAD_SIZE                            1
#define L1_PADDED                              L1_UNPADDED+(2*PAD_SIZE)
#define L1_IMAGE_SIZE 			               L1_PADDED
#define L1_IMAGE_CHANNELS		               3
                          
#define CONV1_1_KERNEL_SIZE 	               3
#define CONV1_1_KERNEL_CHANNELS                L1_IMAGE_CHANNELS	
#define CONV1_1_FILTERS_NUMBERS                64
#define CONV1_1_BIAS_SIZE                      CONV1_1_FILTERS_NUMBERS

#define CONV1_2_KERNEL_SIZE 	               3
#define CONV1_2_KERNEL_CHANNELS                CONV1_1_FILTERS_NUMBERS	
#define CONV1_2_FILTERS_NUMBERS                64
#define CONV1_2_BIAS_SIZE                      CONV1_2_FILTERS_NUMBERS

#define CONV1_OUTPUT_SIZE                      L1_IMAGE_SIZE - CONV1_2_KERNEL_SIZE + 1
#define CONV1_OUTPUT_CHANNELS                  CONV1_2_FILTERS_NUMBERS

#define POOL1_INPUT_SIZE                       CONV1_OUTPUT_SIZE  //SHOULD BE CHANGED IN THE DUNC
#define POOL1_CHANNELS                         CONV1_OUTPUT_CHANNELS
#define POOL_STRIDE                            2  
#define POOL1_OUTPUT_SIZE                      POOL1_INPUT_SIZE/2   //SHOULD BE CHANGED IN THE FUNC






#define L2_UNPADDED                            POOL1_OUTPUT_SIZE
#define L2_PAD_SIZE                            1
#define L2_PADDED                              L2_UNPADDED+(2*PAD_SIZE)
#define L2_FMAP_SIZE 			               L2_PADDED
#define L2_FMAP_CHANNELS		               POOL1_CHANNELS

#define CONV2_1_KERNEL_SIZE 	               3
#define CONV2_1_KERNEL_CHANNELS                L2_FMAP_CHANNELS	
#define CONV2_1_FILTERS_NUMBERS                128
#define CONV2_1_BIAS_SIZE                      CONV2_1_FILTERS_NUMBERS

#define CONV2_2_KERNEL_SIZE 	               3
#define CONV2_2_KERNEL_CHANNELS                CONV2_1_FILTERS_NUMBERS	
#define CONV2_2_FILTERS_NUMBERS                128
#define CONV2_2_BIAS_SIZE                      CONV2_2_FILTERS_NUMBERS

#define CONV2_OUTPUT_SIZE                      L2_FMAP_SIZE - CONV2_2_KERNEL_SIZE + 1
#define CONV2_OUTPUT_CHANNELS                  CONV2_2_FILTERS_NUMBERS

#define POOL2_INPUT_SIZE                       CONV2_OUTPUT_SIZE  
#define POOL2_CHANNELS                         CONV2_OUTPUT_CHANNELS  
#define POOL_STRIDE                            2  
#define POOL2_OUTPUT_SIZE                      POOL2_INPUT_SIZE/2






#define L3_UNPADDED                            POOL2_OUTPUT_SIZE
#define L3_PAD_SIZE                            1
#define L3_PADDED                              L3_UNPADDED+(2*PAD_SIZE)
#define L3_FMAP_SIZE 			               L3_PADDED
#define L3_FMAP_CHANNELS		               POOL2_CHANNELS   //128

#define CONV3_1_KERNEL_SIZE 	               3
#define CONV3_1_KERNEL_CHANNELS                L3_FMAP_CHANNELS	
#define CONV3_1_FILTERS_NUMBERS                256
#define CONV3_1_BIAS_SIZE                      CONV3_1_FILTERS_NUMBERS

#define CONV3_2_KERNEL_SIZE 	               3
#define CONV3_2_KERNEL_CHANNELS                CONV3_1_FILTERS_NUMBERS	
#define CONV3_2_FILTERS_NUMBERS                256
#define CONV3_2_BIAS_SIZE                      CONV3_2_FILTERS_NUMBERS

#define CONV3_3_KERNEL_SIZE 	               3
#define CONV3_3_KERNEL_CHANNELS                CONV3_2_FILTERS_NUMBERS	
#define CONV3_3_FILTERS_NUMBERS                256
#define CONV3_3_BIAS_SIZE                      CONV3_3_FILTERS_NUMBERS

#define CONV3_OUTPUT_SIZE                      L3_FMAP_SIZE - CONV3_3_KERNEL_SIZE + 1
#define CONV3_OUTPUT_CHANNELS                  CONV3_3_FILTERS_NUMBERS

#define POOL3_INPUT_SIZE                       CONV3_OUTPUT_SIZE  
#define POOL3_CHANNELS                         CONV3_OUTPUT_CHANNELS
#define POOL_STRIDE                            2  
#define POOL3_OUTPUT_SIZE                      POOL3_INPUT_SIZE/2






#define L4_UNPADDED                            POOL3_OUTPUT_SIZE
#define L4_PAD_SIZE                            1
#define L4_PADDED                              L4_UNPADDED+(2*PAD_SIZE)
#define L4_FMAP_SIZE 			               L4_PADDED
#define L4_FMAP_CHANNELS		               POOL4_CHANNELS   //256

#define CONV4_1_KERNEL_SIZE 	               3
#define CONV4_1_KERNEL_CHANNELS                L4_FMAP_CHANNELS	
#define CONV4_1_FILTERS_NUMBERS                512
#define CONV4_1_BIAS_SIZE                      CONV4_1_FILTERS_NUMBERS

#define CONV4_2_KERNEL_SIZE 	               3
#define CONV4_2_KERNEL_CHANNELS                CONV4_1_FILTERS_NUMBERS	
#define CONV4_2_FILTERS_NUMBERS                512
#define CONV4_2_BIAS_SIZE                      CONV4_2_FILTERS_NUMBERS

#define CONV4_3_KERNEL_SIZE 	               3
#define CONV4_3_KERNEL_CHANNELS                CONV4_2_FILTERS_NUMBERS	
#define CONV4_3_FILTERS_NUMBERS                512
#define CONV4_3_BIAS_SIZE                      CONV4_3_FILTERS_NUMBERS

#define CONV4_OUTPUT_SIZE                      L4_FMAP_SIZE - CONV4_3_KERNEL_SIZE + 1
#define CONV4_OUTPUT_CHANNELS                  CONV4_3_FILTERS_NUMBERS

#define POOL4_INPUT_SIZE                       CONV4_OUTPUT_SIZE  
#define POOL4_CHANNELS                         CONV4_OUTPUT_CHANNELS
#define POOL_STRIDE                            2  
#define POOL4_OUTPUT_SIZE                      POOL4_INPUT_SIZE/2






#define L5_UNPADDED                            POOL4_OUTPUT_SIZE
#define L5_PAD_SIZE                            1
#define L5_PADDED                              L5_UNPADDED+(2*PAD_SIZE)
#define L5_FMAP_SIZE 			               L5_PADDED
#define L5_FMAP_CHANNELS		               POOL5_CHANNELS   

#define CONV5_1_KERNEL_SIZE 	               3
#define CONV5_1_KERNEL_CHANNELS                L5_FMAP_CHANNELS	
#define CONV5_1_FILTERS_NUMBERS                512
#define CONV5_1_BIAS_SIZE                      CONV5_1_FILTERS_NUMBERS

#define CONV5_2_KERNEL_SIZE 	               3
#define CONV5_2_KERNEL_CHANNELS                CONV5_1_FILTERS_NUMBERS	
#define CONV5_2_FILTERS_NUMBERS                512
#define CONV5_2_BIAS_SIZE                      CONV5_2_FILTERS_NUMBERS

#define CONV5_3_KERNEL_SIZE 	               3
#define CONV5_3_KERNEL_CHANNELS                CONV5_2_FILTERS_NUMBERS	
#define CONV5_3_FILTERS_NUMBERS                512
#define CONV5_3_BIAS_SIZE                      CONV5_3_FILTERS_NUMBERS

#define CONV5_OUTPUT_SIZE                      L5_FMAP_SIZE - CONV5_3_KERNEL_SIZE + 1
#define CONV5_OUTPUT_CHANNELS                  CONV5_3_FILTERS_NUMBERS

#define POOL5_INPUT_SIZE                       CONV5_OUTPUT_SIZE  
#define POOL5_CHANNELS                         CONV5_OUTPUT_CHANNELS
#define POOL_STRIDE                            2  
#define POOL5_OUTPUT_SIZE                      POOL5_INPUT_SIZE/2


