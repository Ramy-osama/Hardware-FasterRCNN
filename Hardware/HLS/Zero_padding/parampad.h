#define matrix_dim_input 3
#define number_ofpadding 1
#define Channels         3
#define HW_COSIM

void matrixpadding(
	int matrix_input[Channels][matrix_dim_input][matrix_dim_input],
	int matrix_paded[Channels][(matrix_dim_input+number_ofpadding*2)][(matrix_dim_input+number_ofpadding*2)]
);	
