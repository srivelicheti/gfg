// LargestRegionOf1s.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <fstream>
#include <algorithm>
#include <tuple>
#include <vector>

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

void DFS(int** arr, bool** visited ,int i, int j,int& n, int& m ,int& curLen, int& maxLen) {
	if (visited[i][j] || arr[i][j] == 0) {
		return;
	}

	curLen++;
	visited[i][j] = true;
	maxLen = max(curLen, maxLen);
	for (auto p : GetAdjacent(i, j, n, m)) {
		if (visited[p.first][p.second] || arr[p.first][p.second] == 0)
			continue;
		DFS(arr, visited, p.first, p.second, n, m, curLen, maxLen);
	}

}

void SolveOne() {
	int n, m;
	cin >> n >> m;
	int** arr = new int*[n];
	bool** visited = new bool*[n];

	for (int i = 0; i < n; i++)
	{
		arr[i] = new int[m];
		visited[i] = new bool[m];
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
			visited[i][j] = false;
		}
	}
	int curLen;
	int maxLen = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!visited[i][j] && arr[i][j] != 0) {
				curLen = 0;
				DFS(arr, visited, i, j, n, m, curLen, maxLen);
			}
		}
	}
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
	cin >> t;
	while (t--) {
		SolveOne();
	}

								 //code
	return 0;
}
