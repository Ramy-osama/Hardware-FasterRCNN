#include<iostream>
#include"parampad.h"
using namespace std;


int main()
{
	int matrix_input[matrix_dim_input][matrix_dim_input]={ {1, 2, 3} , {4, 5, 6}, {7, 8, 9} };
	int matrix_paded[(matrix_dim_input+number_ofpadding*2)][(matrix_dim_input+number_ofpadding*2)]={0};
	
	matrixpadding(matrix_input, matrix_paded);
	
	
	for( int i = 0 ; i <(matrix_dim_input+number_ofpadding*2);  i++)
	{
		cout<<endl;
		for (int j = 0 ; j < (matrix_dim_input+number_ofpadding*2) ; j++)
		{
			cout<<matrix_paded[i][j];
		}
	
	}
	
	
	
	
}