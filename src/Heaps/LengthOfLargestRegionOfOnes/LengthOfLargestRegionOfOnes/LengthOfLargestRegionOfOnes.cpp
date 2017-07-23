// LengthOfLargestRegionOfOnes.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int nx[] = { -1,-1, 0 ,1,1,1,0,-1 };
int ny[] = { 0,-1,-1,-1,0,1,1, 1 };

bool IsSafe(int x, int y, int& n, int& m)
{
	return x >= 0 && y >= 0 && x < n && y < m;
}

void Solve(int x, int y, int px, int py , int n, int m, int** arr ,bool** v , int len, int& maxLen)
{
	v[x][y] = true;

	if ((px == -1 && py == -1) || arr[px][py] == 0)
		len = arr[x][y] == 1 ? 1 : 0;
	else
		len = arr[x][y] == 1 ? (len + 1) : 0;

	maxLen = max(len, maxLen);

	int nx1Arr[8] = {-1,-1,-1,-1,-1,-1,-1,-1};
	int ny1arr[8] = { -1, -1, -1, -1, -1, -1, -1, -1 };
	int k = 0; int j = 7;

	for (int i = 0; i < 8; i++)
	{
		auto nx1 = x + nx[i];
		auto ny1 = y + ny[i];
		if (IsSafe(nx1, ny1, n, m))
		{
			if(arr[nx1][ny1] == 0)
			{
				nx1Arr[j] = nx1;
				ny1arr[j] = ny1;
				j--;
			}
			else
			{
				nx1Arr[k] = nx1;
				ny1arr[k] = ny1;
				k++;
			}
		}

	}

	for(int i=0;i<8;i++)
	{
		auto nx1 = nx1Arr[i];
		auto ny1 = ny1arr[i];

		if(IsSafe(nx1,ny1,n,m) && v[nx1][ny1] == false)
		{
			Solve(nx1, ny1, x, y, n, m, arr, v, len, maxLen);
		}
	}

}

void SolveOne(int n, int m)
{
	
	int** arr = new int*[n];
	bool** v = new bool*[n];
	for (int i = 0; i < n; i++) {
		arr[i] = new int[m];
		v[i] = new bool[m];

	}
	//memset(v, false, sizeof(v[0])*n*m);
	for(int i = 0;i<n;i++)
	{
		for(int j = 0;j<m;j++)
		{
			cin >> arr[i][j];
			v[i][j] = false;
		}
	}
	int len = 0;
	int maxLen = 0;
	Solve(0, 0, -1, -1, n, m, arr, v, len, maxLen);
	cout << maxLen << endl;


}

int main()
{
#if _DEBUG
	std::ifstream ins("input.txt");
	std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	std::cin.rdbuf(ins.rdbuf()); //redirect std::cin to in.txt!
#endif
	int t;
	std::cin >> t;

	while(t--)
	{
		int n, m;
		cin >> n >> m;

		SolveOne(n, m);

	}



    return 0;
}

