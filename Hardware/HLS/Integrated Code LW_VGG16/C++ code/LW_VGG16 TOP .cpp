#include "defines.h"
#include "allweights.h"
#include<iostream>
using namespace std;
const int POOL_STRIDE=2;
void flattening_1( float conv_op[POOL2_CHANNELS][POOL2_OUTPUT_SIZE][POOL2_OUTPUT_SIZE],
                       float flattened[POOL2_CHANNELS*POOL2_OUTPUT_SIZE*POOL2_OUTPUT_SIZE]);
void LW_VGG(float image[L1_IMAGE_CHANNELS][L1_UNPADDED][L1_UNPADDED],float Fc_output_3[Last_Layer])

{
	 float matrix_paded0[L1_IMAGE_CHANNELS][L1_PADDED ][L1_PADDED ];
	 float conv_op0[CONV1_OUTPUT_CHANNELS][CONV1_OUTPUT_SIZE][CONV1_OUTPUT_SIZE];
	 float matrix_paded1[L0_IMAGE_CHANNELS][L0_PADDED ][L0_PADDED ];
	 float conv_op1[CONV1_OUTPUT_CHANNELS][CONV1_OUTPUT_SIZE][CONV1_OUTPUT_SIZE];
	 float out_pool1[POOL1_CHANNELS][POOL1_OUTPUT_SIZE][POOL1_OUTPUT_SIZE];
	 float matrix_paded_2[L2_FMAP_CHANNELS ][L2_PADDED ][L2_PADDED ];
	 float conv_op_2[CONV2_OUTPUT_CHANNELS][CONV2_OUTPUT_SIZE][CONV2_OUTPUT_SIZE];
	 float out_pool2[POOL2_CHANNELS][POOL2_OUTPUT_SIZE][POOL2_OUTPUT_SIZE];
	 float flattened_1[POOL2_CHANNELS*POOL2_OUTPUT_SIZE*POOL2_OUTPUT_SIZE]={0};
	 float Fc_output_1[outputsizefc1]={0}; 
	 float Fc_output_2[outputsizefc1]={0};
	
	 
	matrixpadding_0(image,matrix_paded0);

	conv_0 ( matrix_paded0,weights0,bias0,conv_op0);

    matrixpadding_1(conv_op0,matrix_paded1);
	conv_1 ( matrix_paded1,weights1,bias1,conv_op1);
	matrixpadding_1(conv_op1,matrix_paded1);
	conv_1 ( matrix_paded1,weights2,bias2,conv_op1);
	matrixpadding_1(conv_op1,matrix_paded1);
	conv_1 ( matrix_paded1,weights3,bias3,conv_op1);	
	
     Max_Pooling_1(conv_op1 , POOL_STRIDE,out_pool1);

	  matrixpadding_2(out_pool1,matrix_paded_2 );
	  conv_2 ( matrix_paded_2,weights5, bias5,conv_op_2);
	  matrixpadding_2(conv_op_2,matrix_paded_2 );
	  conv_2 ( matrix_paded_2,weights6, bias6,conv_op_2);
	 
	 Max_Pooling_2(conv_op_2 ,POOL_STRIDE,out_pool2);

	 flattening_1(out_pool2,flattened_1); 
	
	 fc1 ( flattened_1,bias9,weigths9, Fc_output_1);
	 fc2 ( Fc_output_1, bias10,weights10,Fc_output_2);
	 fc3 ( Fc_output_2,bias11,weights11,Fc_output_3);
	//softmax(Fc_output_3);
	for (int i=0 ; i<Last_Layer ; i++)
		   cout<<Fc_output_3[i]<<endl;
	 
	 
	
}