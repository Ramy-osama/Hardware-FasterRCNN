#include<iostream>
#include"parampad.h"
using namespace std;


int main()
{
	int matrix_input[Channels][matrix_dim_input][matrix_dim_input]={ {  { 0, 1, 5 }, {2, 1, 0}, {3, 5, 9} }, { {7, 6, 0}, {2, 0, 3}, {4, 2, 1} } , { {3, 2, 1}, {0, 6, 7}, {5, 6, 0} } };
	int matrix_paded[Channels][(matrix_dim_input+number_ofpadding*2)][(matrix_dim_input+number_ofpadding*2)]={0};


	matrixpadding(matrix_input, matrix_paded);

	
for( int f = 0 ; f <Channels;  f++)
{          cout<<endl;
	for( int i = 0 ; i <(matrix_dim_input+number_ofpadding*2);  i++)
	{
		cout<<endl;
		for (int j = 0 ; j < (matrix_dim_input+number_ofpadding*2) ; j++)
		{
			cout<<matrix_paded[f][i][j];
		}
	
	}
	
}
	
	
}
