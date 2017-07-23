// ReplaceOsWithXs.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include<vector>
#include <tuple>

using namespace std;

const int mx[8] = { -1,0,1,0 };
const int my[8] = { 0, 1,0,-1 };

bool isOutSide(int x, int y, int& n, int& m) {
	return x <0 || y <0 || x >= n || y >= m;
}


bool DfsUtil(int x, int y, char** arr, bool** visited, vector<pair<int, int>>& path, int& n, int& m) {

	if (isOutSide(x, y, n, m))
		return false;

	
	if (arr[x][y] == 'X')
		return true;
	visited[x][y] = true;
	path.push_back({ x,y });

	bool isInside = true;
	for (int i = 0; i<4; i++) {

		int nx = x + mx[i];
		int ny = y + my[i];
		if(!isOutSide(nx,ny,n,m) && visited[nx][ny])
			continue;
			isInside = DfsUtil(nx, ny, arr, visited, path, n, m);

		if (!isInside)
			break;
	}
	visited[x][y] = false;
	return isInside;
}

void Solve(int n, int m) {
	auto arr = new char*[n];
	auto visited = new bool*[n];
	for (int i = 0; i<n; i++) {
		arr[i] = new char[m];
		visited[i] = new bool[m];
		for (int j = 0; j<m; j++) {
			cin >> arr[i][j];
			visited[i][j] = false;
		}
	}

	for (int i = 0; i<n; i++) {
		for (int j = 0; j<m; j++) {
			if (arr[i][j] == 'O' && !visited[i][j]) {
				vector<pair<int, int>> path;
				bool isInside = DfsUtil(i, j, arr, visited, path, n, m);
				if (isInside) {
					for (auto p : path) {
						arr[p.first][p.second] = 'X';
					}
				}

			}
		}
	}

	for (int i = 0; i<n; i++) {
		for (int j = 0; j<m; j++) {
			cout << arr[i][j] << " ";
		}
	}
	cout << endl;
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
		int n, m;
		cin >> n >> m;

		Solve(n, m);

	}

	//code
	return 0;
}

