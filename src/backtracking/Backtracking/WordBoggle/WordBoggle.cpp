// WordBoggle.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

vector<pair<int, int>> GetAdjacent(int i, int j, int& n, int& m) {
	vector < pair<int, int>> v;
	if (i - 1 >= 0) {
		v.push_back({ i - 1,j });
	}
	if (i - 1 >= 0 && j - 1 >= 0) {
		v.push_back({ i - 1,j - 1 });
	}
	if (i - 1 >= 0 && j + 1 < m) {
		v.push_back({ i - 1,j + 1 });
	}
	if (j - 1 >= 0) {
		v.push_back({ i,j - 1 });
	}
	if (j + 1 < m) {
		v.push_back({ i,j + 1 });
	}
	if (i + 1 < n) {
		v.push_back({ i + 1,j });
		if (j + 1 < m) {
			v.push_back({ i + 1,j + 1 });
		}
		if (j - 1 >= 0) {
			v.push_back({ i + 1,j - 1 });
		}
	}

	return v;
}

int main()
{
#if _DEBUG
	std::ifstream ins("in.txt");
	std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	std::cin.rdbuf(ins.rdbuf()); //redirect std::cin to in.txt!
#endif


	return 0;
}