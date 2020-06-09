#define matrix_dim_input 3
#define number_ofpadding 4

void matrixpadding(
	int matrix_input[matrix_dim_input][matrix_dim_input],
	int matrix_paded[(matrix_dim_input+number_ofpadding*2)][(matrix_dim_input+number_ofpadding*2)]
);	