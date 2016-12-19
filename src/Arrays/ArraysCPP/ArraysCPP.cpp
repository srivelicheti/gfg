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

int main()
{
	
	int* harray = new int[2]{100,200};
	int sarray[2]{ 400,500 };

	int* psarray = sarray;
	++harray;
	std::cout << *harray << endl;
	(psarray)++;
	std::cout << *psarray << endl;
 	int temp;
	std::cin >> temp;
    return 0;
}

