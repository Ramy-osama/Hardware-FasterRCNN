//============================================================================
// Name        : relu10.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

#define COLUMN_SIZE 4
#define Size_Row 4

int array[COLUMN_SIZE][Size_Row]={0};
void relu_array2d(const int a[] [COLUMN_SIZE], int rowSize)
{



    for (int row = 0; row < rowSize; row++)
    {
        for (int column = 0; column < COLUMN_SIZE; column++)
        {
            if(a[row][column]>=0)
            	{array[row][column]=a[row][column];
            	}
        }
    }


}
int main()
{
    int m[COLUMN_SIZE][Size_Row];
    for(int i=0;i<COLUMN_SIZE;i++)
           {
           	for(int j=0;j<Size_Row;j++)
           	{cin>>m[i][j];
           	}
           }

    relu_array2d(m,Size_Row);
    for(int i=0;i<COLUMN_SIZE;i++)
           {
           	for(int j=0;j<Size_Row;j++)
           	{
           		cout <<array[i][j];
           		cout <<"     ";
           	}
           }

    return 0;
}
