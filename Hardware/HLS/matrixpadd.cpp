#include"parampad.h"

void matrixpadding(
	int matrix_input[matrix_dim_input][matrix_dim_input],
	int matrix_paded[matrix_dim_input+number_ofpadding*2][matrix_dim_input+number_ofpadding*2]
)	
{
     
	
	for( int i = number_ofpadding,m=0 ; i < (matrix_dim_input+number_ofpadding*2)-number_ofpadding;  i++,m++)
	{
		
		for (int j = number_ofpadding,n=0; j <(matrix_dim_input+number_ofpadding*2)-number_ofpadding ; j++,n++)
		{
			
			
				matrix_paded[i][j] = matrix_input[m][n];
			
		}
	
	}
}
