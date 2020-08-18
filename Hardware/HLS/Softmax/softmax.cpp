#include <iostream>
#include <math.h>
#define size 7
using namespace std;
void softmax(float arr[size])
{
	float sum=0;
	for (int i=0;i<size;i++)
	{
		sum+=expf(arr[i]);
		
	}
	for (int i=0;i<size;i++)
	{
		arr[i]=(expf(arr[i]))/sum;
	}
}
int main()
{
float arr[size]={1.0, 2.0, 3.0, 4.0, 1.0, 2.0, 3.0};
softmax(arr);
for (int i=0;i<size;i++)
{
	cout<<arr[i];
	cout<<endl;
}
return 0;
}
