#include <iostream>
#include <math.h>
#define size 7

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
