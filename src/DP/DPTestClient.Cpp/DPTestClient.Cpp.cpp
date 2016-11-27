// DPTestClient.Cpp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "NStackBooks.h"
#include <iostream>
#include "DPFunctions.h"
#include <string>
#include <sstream>

using namespace std;

int main()
{
	/*NStackBooks books;
	int a[4]{ 4,2,1,5 };
	std::cout << books.GetMaxBooks(a, 4, 8);*/
	// , 4, -1, -2, 1, 5, -3
	int n;
	cin >> n;

	for(int i = 0 ;i<n ;i++)
	{
		int l; 
		cin >> l;
		int* arr = new int[l];
		std::string arrStr;
		//cin >> arrStr;
		for(int j=0;j<l;j++)
		{
			cin >> arr[j];
		}
		cout << GetLargesetSubArray(arr, l);
		delete arr;

	}

	//int test[] = { -2,-3 , 4, -1, -2, 1, 5, -3 , 2 };
	//-2 -3 4 -1 -2 1 5 -3 2
//	cout << GetLargesetSubArray(test, 9);

	return 0;
}

