//============================================================================
// Name        : relu12.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


#include <iostream>
using namespace std;

#define SIZE 4


int array[SIZE]={0};
void relu_array1d(const int a[] )
{



    for (int row = 0; row < SIZE; row++)
    {


            if(a[row]>=0)
            	{array[row]=a[row];
            	}

    }


}
int main()
{
    int m[SIZE];
    for(int i=0;i<SIZE;i++)
           {

           	cin>>m[i];

           }

    relu_array1d(m);
    for(int i=0;i<SIZE;i++)
           {


           		cout <<array[i];
           		cout <<"     ";

           }

    return 0;
}
