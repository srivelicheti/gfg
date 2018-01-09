// NQueen.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
using namespace std;

bool IsValidRowPos(bool** mem, int i, int j, int n)
{
	bool valid = true;
	for (int k = 0; k<n; k++)
	{
		if (mem[i][k])
		{
			valid = false;
			break;
		}
	}

	return valid;
}

bool IsValidColPos(bool** mem, int i, int j, int n)
{
	bool valid = true;
	for(int k=0;k<n; k++)
	{
		if(mem[k][j])
		{
			valid = false;
			break;
		}
	}

	return valid;
}

bool IsValidDiag(bool** mem, int i, int j, int n)
{
	bool valid = true;
	int ti = i;
	int tj = j;
	while (ti >= 0 && tj >= 0)
	{
		if(mem[ti][tj])
		{
			valid = false;
			break;
		}
		ti--; tj--;
	}

	if (!valid)
		return false;

	ti = i;
	tj = j;

	while (ti >= 0 && tj < n)
	{
		if (mem[ti][tj])
		{
			valid = false;
			break;
		}
		ti--; tj++;
	}
	
	if (!valid)
		return false;
	ti = i;
	tj = j;


	while (ti < n && tj < n)
	{
		if (mem[ti][tj])
		{
			valid = false;
			break;
		}
		ti++; tj++;
	}
	if (!valid)
		return false;

	ti = i;
	tj = j;


	while (ti < n && tj >= 0)
	{
		if (mem[ti][tj])
		{
			valid = false;
			break;
		}
		ti++; tj--;
	}
		return valid;


}

bool IsValid(bool** mem, int i, int j, int n)
{
	if (!IsValidRowPos(mem, i, j, n))
		return false;

	return IsValidDiag(mem, i, j, n);
}

void SolveInternal(bool** mem, int q, int n, bool& found)
{
	if (q >= n) {
		found = true;
		cout << "[";
		for(int j=0;j<n;j++)
		{
			
			for(int i=0;i<n;i++)
			{
				if(mem[i][j])
				cout << (i + 1) << " ";
			}
		}
		cout << "] ";
		return;
	}

	for(int i=0;i<n;i++)
	{
		if(IsValid(mem,i,q,n))
		{
			mem[i][q] = true;
			SolveInternal(mem, q + 1, n, found);
			mem[i][q] = false;
		}
	}

}

void Solve(int n)
{
	auto mem = new bool*[n];
	for(int i=0;i<n;i++)
	{
		mem[i] = new bool[n];
		for(int j =0;j<n;j++)
		{
			mem[i][j] = false;
		}
	}
	bool found = false;
	SolveInternal(mem, 0, n, found);
	if (found)
		cout << endl;
	else
		cout << "-1" << endl;


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
		Solve(n);

	}
	

	return 0;
}