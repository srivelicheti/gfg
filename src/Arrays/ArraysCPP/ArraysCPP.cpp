// ArraysCPP.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdio.h"
#include <iostream>
using namespace std;

/*You are required to complete this method*/
int max_sum(int A[], int N)
{
	int max = 0;

	int cumSum = 0;
	for (int i = 0; i < N; ++i)
	{
		cumSum += A[i];
		max += A[i] * i;
	}
	int currentVal = max;
	for(int i=1;i<N;++i)
	{
		int nextVal = currentVal - (cumSum - A[i - 1]) + (A[i-1] * (N - 1));

		if (nextVal > max)
			max = nextVal;

		currentVal = nextVal;
	}

	return  max;
	//Your code here
}


void Move(int pos, int* arr , int placeHolder)
{
	
	if (arr[pos] == pos)
		return;

	if (arr[arr[pos]] == placeHolder)
	{
		//The value in the position to be moved to is already moved away to a new position.
		arr[arr[pos]] = -1 * pos; //use negative values to denote an already moved element so that this will not get moved again.
		arr[pos] = placeHolder;
	}
	else
	{
		auto tempVal = arr[pos];
		arr[pos] = placeHolder;
		Move(tempVal, arr, placeHolder);
		arr[tempVal] = -1 * pos;
	}

	
}

void ReArrangeArray(int* a, int n)
{
	//Placeholder to denote a moved and empty position in an array. We are taking the size of array  as there can be no value
	//equal to the length of array in the array it self.
	int placeHolder = -1 * n;
	for (int i = 0; i < n; ++i)
	{
		if(a[i] != i && a[i] >0)
		{
			Move(i, a, placeHolder);
		}
	}
	for (int i = 0; i < n; ++i)
	{
		if(a[i] < 0)
			a[i] = -1 * a[i];
	}
}



int main()
{
	
	//int* harray = new int[5]{ 2,0,1,4,3 };

	int* harray = new int[7]{ 0,2,6,3,1,5,4 };
	ReArrangeArray(harray, 7);
	for (int i = 0; i < 7; ++i)
	{
		cout << harray[i] << " ";
	}
	int temp;
	std::cin >> temp;
    return 0;
}

