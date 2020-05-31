/*
 * main.cpp
 *
 *  Created on: May 30, 2020
 *      Author: OMAR
 */




#include <iostream>
#include "matrix.h"
using namespace std;


const int COLUMN_SIZE = 100;

void ReLu_array(const int a[] [COLUMN_SIZE], int rowSize)
{
	int total=0;
    int array [100][100]={0};
    for (int row = 0; row < rowSize; row++)
    {
        for (int column = 0; column < COLUMN_SIZE; column++)
        {
            if(a[row][column]<=0)
            	array[row][column]=0;
            else
            	array[row][column]=a[row][column];
        }
    }


}

int main() {
	int flag;
	if(flag=0)
	{
    Matrix m;
    Matrix mynew;
        for( int i = 0; i< m.rows_; ++i )
        for (int j=0; j< m.cols_; ++j) {
            if (m(i,j) <= 0){
                mynew(i,j)=(0.0);
            }
            else mynew(i,j)=(m(i,j));
        }

	}else
	{
	    int m[100][100]={0};
	    ReLu_array(m,100);



	    return 0;

	}
}



