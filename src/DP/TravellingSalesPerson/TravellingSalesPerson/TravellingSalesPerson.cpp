// TravellingSalesPerson.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

void SolveTsp(int** mat, int n)
{
	int mask = pow(2, n);
	auto mem = new int*[mask];
	for(int i=0;i<mask;i++)
	{
		//mem[i] = new int
	}
}

int main()
{
#if _DEBUG
	std::ifstream ins("input.txt");
	std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	std::cin.rdbuf(ins.rdbuf()); //redirect std::cin to in.txt!
#endif
	int t;
	cin >> t;

	while(t--)
	{
		int n;
		cin >> n;

		auto mat = new int*[n];
		for(int i=0;i<n;i++)
		{
			mat[i] = new int[n];
			for(int j=0;j<n;j++)
			{
				cin >> mat[i][j];
			}
		}


	}
	
	return 0;
}
