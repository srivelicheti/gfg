// CountOfStringsWithABC.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <fstream>
using namespace std;

int Solve(int*** mem, int l, int i, int j) {
	if (l <0 || i <0 || j <0)
		return 0;
	if (l == 0)
		return 1;

	if (mem[l][i][j] != -1) {
		return mem[l][i][j];
	}

	int a = Solve(mem, l - 1, i, j);// *l;

	int b = Solve(mem, l - 1, i - 1, j);// *l;
	int c = Solve(mem, l - 1, i, j - 1);// *l;

	mem[l][i][j] = a + b + c;

	return mem[l][i][j];

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

		auto mem = new int**[n + 1];
		for (int i = 0; i<=n; i++) {
			mem[i] = new int*[2];
			for (int j = 0; j<2; j++) {
				mem[i][j] = new int[3];
				for (int k = 0; k<3; k++) {
					if (i == 0)
						mem[i][j][k] = 1;
					else
						mem[i][j][k] = -1;
				}
			}
		}
		cout << Solve(mem, n, 1, 2) << endl;

	}

	//code
	return 0;
}

