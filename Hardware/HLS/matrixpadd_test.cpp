#include<iostream>
#include"parampad.h"

using namespace std;




int main()
{
	int matrix_input[matrix_dim_input][matrix_dim_input]={ {1, 0, 0} , {0, 1, 0}, {0, 0, 1} };
	int matrix_paded[matrix_dim_paded][matrix_dim_paded];
	
	matrixpadding(matrix_input, matrix_paded);
	
	
	for( int i = 0 ; i < matrix_dim_paded;  i++)
	{
		for (int j = 0 ; j < matrix_dim_paded ; j++)
		{
			cout<<matrix_paded[i][j];
		}
	
	}
	
	
	
	
}