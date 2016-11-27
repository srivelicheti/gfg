#include "stdafx.h"
#include <iostream>
#include <array>

int GetLargesetSubArray(int a[], int size)
{
	int maxSize = 0;// a[0];
	int finalmax = 0;

	int test[] = {1,2,3};
	int currentReduction = 0;
 
	int indivMax = a[0];
	for(int i = 0;i<size;i++)
	{
		if (a[i] > indivMax)
			indivMax = a[i];
		
		if (a[i] + maxSize < 0)
		{
			maxSize = 0;
		}
		else
			maxSize = maxSize + a[i];

		if (maxSize > finalmax)
			finalmax = maxSize;
	}
	if (finalmax == 0 && indivMax < 0)
		finalmax = indivMax;
	return finalmax;

	
}