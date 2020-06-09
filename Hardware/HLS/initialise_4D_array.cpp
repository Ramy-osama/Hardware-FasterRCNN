#include<iostream>
using namespace std;

int main()
{
//int arr[3][3][3][3] ={ { {  { 0, 1, 5 }, {2, 1, 0}, {3, 5, 9} }, { {7, 6, 0}, {2, 0, 3}, {4, 2, 1} } , { {3, 2, 1}, {0, 6, 7}, {5, 6, 0} } } ,  { {  { 3 , 7, 1 }, {9, 0, 2}, {5, 6, 3} }, { {5, 2, 1}, {3, 6, 0}, {2, 1, 4} } , { {0, 5, 1}, {3, 7, 4}, {6, 2, 0} } }, { {  { 0, 1, 5 }, {2, 1, 0}, {3, 5, 9} }, { {7, 6, 0}, {2, 0, 3}, {4, 2, 1} } , { {3, 2, 1}, {0, 6, 7}, {5, 6, 0} } } };

int arr[2][3][3][3] ={ { {  { 0, 1, 5 }, {2, 1, 0}, {3, 5, 9} }, { {7, 6, 0}, {2, 0, 3}, {4, 2, 1} } , { {3, 2, 1}, {0, 6, 7}, {5, 6, 0} } }, { {  { 3 , 7, 1 }, {9, 0, 2}, {5, 6, 3} }, { {5, 2, 1}, {3, 6, 0}, {2, 1, 4} } , { {0, 5, 1}, {3, 7, 4}, {6, 2, 0} } } };


for(int filter_number = 0; filter_number < 2 ; filter_number ++)
{
	cout<<"kernel filter"<<filter_number+1<<endl;
	for(int channel = 0 ; channel <3 ; channel ++)
	{
		cout<<"Kernel channel"<<channel+1<<endl;
		for(int row = 0; row < 3 ; row++)
		{
			cout<<endl;
			for(int col = 0 ; col < 3 ; col++)
			{
				cout<< arr[filter_number][channel][row][col]<< "  ";
			}
		}
	}
}


}