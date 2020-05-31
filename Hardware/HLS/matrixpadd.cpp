#include"parampad.h"



void matrixpadding(
	int matrix_input[matrix_dim_input][matrix_dim_input],
	int matrix_paded[matrix_dim_paded][matrix_dim_paded]
	)
{
for( int i = 0 ; i < matrix_dim_paded;  i++)
	{
		for (int j =0; j < matrix_dim_paded ; j++)
		{
			
			
				matrix_paded[i][j] = 0;
			
		}
	
	}
	for( int i = 1,m=0 ; i < matrix_dim_paded-1;  i++,m++)
	{
		for (int j = 1,n=0; j <matrix_dim_paded-1 ; j++,n++)
		{
			
			
				matrix_paded[i][j] = matrix_input[m][n];
			
		}
	
	}
}

