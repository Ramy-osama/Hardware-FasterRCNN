#include <iostream>
#include <stdlib.h>
using namespace std;

int relu(int a);
int main()
{
	int matrix_input[3][3]={ {1, -1, 3} , {4, 5, -3}, {7, -2, 9} };
	
	
	

	for( int i = 0 ; i <3;  i++)
	{
		cout<<endl;
		for (int j = 0 ; j < 3; j++)
		{
			matrix_input[i][j]=relu(matrix_input[i][j]);
		}
	
	}
	

	for( int i = 0 ; i <3;  i++)
	{
		cout<<endl;
		for (int j = 0 ; j < 3; j++)
		{
			cout<<matrix_input[i][j];
		}
	
	}
	
	
}
