// InterleavedString.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <cstring>
#include <iostream>
#include <fstream>

using namespace std;

/*
Please note that it's Function problem i.e.
you need to write your solution in the form Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/

const int MAX = 100;

int mem[MAX][MAX];

int Solve(string& a, string& b, string& c, int i, int j) {
	if (i == 0 && j == 0 )
		return 1;

	if (mem[i][j] != -1) {
		cout << "# ";
		return mem[i][j];
	}
	int isInter = -1;
	if (i>0 && a[i - 1] == c[i + j - 1])
		isInter = Solve(a, b, c, i - 1, j);

	if (isInter != 1 && j>0 && b[j - 1] == c[i + j - 1])
		isInter = Solve(a, b, c, i, j - 1);

	if (isInter == -1)
		isInter = 0;

	mem[i][j] = isInter;

	return isInter;
}

/*You are required to complete this method */
bool isInterleave(string A, string B, string C)
{
	int alen = A.length();
	int blen = B.length();
	int clen = C.length();

	memset(mem, -1, sizeof(mem[0][0]) * MAX * MAX);
	int isInter = Solve(A, B, C, alen, blen);

	for (int i = 0; i <= alen; i++) {
		for (int j = 0; j <= blen; j++) {
			if (mem[i][j] == -1)
				cout << "- ";
			else
			cout << mem[i][j] << ' ';
		}
		cout << endl;
	}

	return isInter == 1;
	//Your code here
}

int main() {
#if _DEBUG
	std::ifstream ins("input.txt");
	std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	std::cin.rdbuf(ins.rdbuf()); //redirect std::cin to in.txt!
#endif
	int t;
	cin >> t;
	while (t--)
	{
		string a, b, c;
		cin >> a;
		cin >> b;
		cin >> c;
		cout <<endl << isInterleave(a, b, c) << endl;
	}
	// your code goes here
	return 0;
}

