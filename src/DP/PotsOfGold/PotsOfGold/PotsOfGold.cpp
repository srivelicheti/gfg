// PotsOfGold.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;


/*
Please note that it's Function problem i.e.
you need to write your solution in the form Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/

const int MAX = 101;
int mem[MAX][MAX];

int solve(int a[], int mem[MAX][MAX], int i, int j, int& n) {
	if (i<0 || j > n || i > j)
		return 0;

	if (i == j)
		return a[i];

	if (mem[i][j] != -1)
		return mem[i][j];
	if (j == i + 1) {
		mem[i][j] = max(a[i], a[j]);
		return mem[i][j];
	}

	//picking first coin
	auto sf =  solve(a, mem, i + 2, j, n);  /*second user picks up first*/
	auto ss =  solve(a, mem, i + 1, j - 1, n); /*second user picks up last*/
	auto second = min(sf,ss);
		auto f = a[i] + second;
	auto l = a[j] + min( solve(a, mem, i + 1, j - 1, n),
		 solve(a, mem, i, j - 2, n));

	mem[i][j] = max(f, l);

	return mem[i][j];

}
/*You are required to complete below method */
int maxCoins(int A[], int N)
{

	memset(mem, -1, sizeof(mem[0][0]) * MAX * MAX);
	int lim = N - 1;
	solve(A, mem, 0, lim, lim);

	return mem[0][lim];
	//Your code here
}




int main() {
#if _DEBUG
	std::ifstream ins("input.txt");
	std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	std::cin.rdbuf(ins.rdbuf()); //redirect std::cin to in.txt!
#endif
	// your code goes here
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int a[MAX];
		for (int i = 0; i<n; i++)
		{
			cin >> a[i];
		}

		cout << maxCoins(a, n) << endl;

	}
	return 0;
}

