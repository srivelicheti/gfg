// TSP.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <fstream>
#include <limits>
#include <algorithm>

using namespace std;

int Solve(int** mem, int mask, int v, int n ,int** mat) {

	if (mem[mask][v] != -1)
		return mem[mask][v];

	mem[mask][v] = -1; // numeric_limits<int>::max();

	for (int i = 1; i < n; i++)
	{
		if (i != v) {
			if ((mask & (1 << i)) && mat[v][i]) {
				
				int cost = mat[v][i] + Solve(mem, (mask & (~(1 << v))), i, n, mat);
				if (mem[mask][v] == -1)
					mem[mask][v] = cost;
				mem[mask][v] = min(cost, mem[mask][v]);

			}
		}
	}

}


void Solve(int** mat, int n) {
	int mask = pow(2, n);
	auto mem = new int*[mask];
	for (int i = 0; i < mask; i++) {
		mem[i] = new int[n];
		for (int j = 0; j < n; j++)
		{
			mem[i][j] = -1;
		}
	}

	mem[1][0] = 0;


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
	while (t--) {
		int n;
		cin >> n;

		auto mat = new int*[n];
		for (int i = 0; i < n; i++)
		{
			mat[i] = new int[n];
			for (int j = 0; j < n; j++)
			{
				cin >> mat[i][j];
			}
		}

		Solve(mat, n);
	
	}
								 //code
	return 0;
}

