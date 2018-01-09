// sudoku.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <fstream>
using namespace std;

bool IsSafe(int su[][9], int i, int j, int val) {
	bool safe = true;
	for (int r = 0; r<9; r++) {
		if (r != i) {
			if (su[r][j] == val) {
				safe = false;
				break;
			}
		}
	}
	if (!safe)
		return safe;

	for (int c = 0; c<9; c++) {
		if (c != j) {
			if (su[i][c] == val) {
				safe = false;
				break;
			}
		}
	}

	if (!safe)
		return safe;

	int bis = i;
	int bie = i;
	int bjs = j;
	int bje = j;

	while (bis % 3 != 0) bis--;
	while ((bie +1) % 3 != 0) bie++;
	while (bjs % 3 != 0) bjs--;
	while ((bje +1) % 3 != 0) bje++;

	for (int r = bis; r<=bie; r++) {
		for (int c = bjs; c <= bje; c++) {
			if (r != i && c != j) {
				if (su[r][c] == val) {
					safe = false;
					break;
				}
			}
		}
	}

	return safe;
}


pair<int, int> GetNext(int i, int j) {
	if (j < 8)
	{
		return{ i ,j+1 };
	}
	else
	{
		return{ i+1,0 };
	}
}

bool Solve(int su[][9], int i, int j) {
	if (i >= 9 || j>=9)
		return true;


	if (su[i][j] != 0)
	{
		auto next = GetNext(i, j);
		return Solve(su, next.first, next.second);
	}

	for (int k = 1; k <= 9; k++) {
		if (IsSafe(su, i, j, k)) {
			su[i][j] = k;
			auto next = GetNext(i, j);
			if (Solve(su, next.first, next.second))
				return true;
			su[i][j] = 0;
		}
	}

	return false;

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
		int su[9][9];
		for (int i = 0; i<9; i++) {
			for (int j = 0; j<9; j++)
			{
				cin >> su[i][j];
			}
		}

		Solve(su, 0, 0);

		for (int i = 0; i<9; i++) {
			for (int j = 0; j<9; j++)
			{
				cout<<  su[i][j] <<" ";
			}
		//	cout << endl;
		}

	}

	//code
	return 0;
}
