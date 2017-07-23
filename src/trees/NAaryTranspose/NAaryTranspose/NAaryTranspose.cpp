// NAaryTranspose.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;

int Solve(vector<vector<int>>& v, vector<vector<int>>& d, int c) {
	queue<int> q;
	q.push(c);
	int level = -1;

	while (!q.empty()) {

		level++;
		while (!q.empty()) {
			auto e = q.front();
			q.pop();
			d[level].push_back(e);
		}

		for (auto cur : d[level]) {
			for (auto child : v[cur]) {
				q.push(child);
			}
		}


	}
	return level;
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
		int n, e;
		cin >> n >> e;
		vector<vector<int>> v1(n + 1);
		vector<vector<int>> v2(n + 1);
		vector<vector<int>> d1(n + 1);
		vector<vector<int>> d2(n + 1);
		int temp = e;
		while (temp > 0) {
			int u, v;
			cin >> u >> v;
			v1[u].push_back(v);
			temp = temp - 1;
		}

		temp = e;
		while (temp > 0) {
			int u, v;
			cin >> u >> v;
			v2[u].push_back(v);
			temp = temp - 1;
		}



		int t1Levels = Solve(v1, d1, 1);
		int t2Levels = Solve(v2, d2, 1);
		if (t1Levels == t2Levels) {
			int i = 0;
			bool allEqual = true;
			while (i <= t1Levels) {
				if (d1[i].size() == d2[i].size()) {
					auto cnt = d1[i].size() - 1;
					for (int j = 0; j <= cnt; ++j) {
						if (d1[i][j] != d2[i][cnt - j]) {
							allEqual = false;
							break;
						}
					}

				}
				else {
					allEqual = false;
					break;
				}
				if (!allEqual)
					break;
				i++;
			}
			if (allEqual)
				cout << 1 << endl;
			else
				cout << 0 << endl;
		}
		else {
			cout << 0 << endl;
		}

	}

	//code
	return 0;
}

