// MinCutSquare.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <limits>
#include <cmath>
#include <algorithm>
#include <string>
#include <fstream>
using namespace std;

const int maxarr = 10000;
int mem[maxarr][maxarr];

int solve(int l, int w) {
	if (l <= 0 || w <= 0)
		return 0;
	if (l == w)
		return 1;

	if (l > w)
	{
		auto temp = w;
		w = l;
		l = temp;
	}

	if (mem[l][w] != -1)
		return mem[l][w];

	
	int i = l;
	int minSq = numeric_limits<int>::max();
	while (i > 0) {
		int sq = l / i + solve( w - i, l);
		minSq = min(minSq, sq);
		if (i % 2 != 0)
			break;
		i = i / 2;
	}
	/*if (l % 2 != 0 && w % 2 == 0) {
		auto temp = w;
		w = l;
		l = temp;
		i = l;
		while (i > w)
			i = i / 2;

		while (i > 0) {
			int sq = l / i + solve(mem, w - i, l);
			minSq = min(minSq, sq);
			i = i / 2;
		}

	}*/

	mem[l][w] = minSq;
	return minSq;

}

int main() {

#if _DEBUG
	std::ifstream ins("input.txt");
	std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	std::cin.rdbuf(ins.rdbuf()); //redirect std::cin to in.txt!
#endif

	int t;
	cin >> t;
	
	
	while (t--) {
		memset(mem, -1, sizeof(mem[0][0]) * maxarr * maxarr);
		int l, w;
		cin >> l >> w;
		cout << solve( l, w) << endl;
	}
	//code
	return 0;
}
