void matrixpadding_0(
	float matrix_input[L1_IMAGE_CHANNELS][L1_UNPADDED][L1_UNPADDED],
	float matrix_paded[L1_IMAGE_CHANNELS][L1_PADDED ][L1_PADDED ]
)	
{
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
}
void matrixpadding_1(
	float matrix_input[CONV1_OUTPUT_CHANNELS ][CONV1_OUTPUT_SIZE][CONV1_OUTPUT_SIZE],
	float matrix_paded[CONV1_OUTPUT_CHANNELS ][L0_PADDED ][L0_PADDED ]
)	
{
	for( int f = 0 ; f <CONV1_OUTPUT_CHANNELS;  f++)
	{
	  for( int i = L1_PAD_SIZE,m=0 ; i < (L1_PADDED )-L1_PAD_SIZE;  i++,m++)
	   {
		for (int j = L1_PAD_SIZE,n=0; j <(L1_PADDED )-L1_PAD_SIZE ; j++,n++)
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