// RatMaze.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

#define MAX 100

/*
Please note that it's Function problem i.e.
you need to write your solution in the form Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/

bool inCurPath(int i, int j, vector<pair<int, int>>& path) {
	for (auto p : path) {
		if (p.first == i && p.second == j)
			return true;
	}
	return false;
}

bool IsValid(int i, int j, int n, char d) {
	if (i< 0 || j<0 || i >= n || j >= n)
		return false;
	if (d == 'L') {
		return j - 1 >= 0;
	}
	else if (d == 'R')
		return j + 1<n;
	else if (d == 'D')
		return i + 1 < n;
	else
		return i - 1 >= 0;
}

void Dfs(int i, int j, int n, int maz[MAX][MAX], vector<pair<int, int>>& path, vector<char>& dir, int pi, int pj, vector<string>& paths)
{
	if (i == n - 1 && j == n - 1) {
		string cp = "";
		for (auto c : dir) {
			cp = cp + c;
		}
		paths.push_back(cp);
		return;
	}
	if (IsValid(i, j, n, 'D')) {
		int ti = i + 1;
		int tj = j;
		if (maz[ti][tj] == 1 && !inCurPath(ti, tj, path)) {
			path.push_back({ ti,tj });
			dir.push_back('D');
			Dfs(ti, tj, n, maz, path, dir, i, j, paths);
			dir.pop_back();
			path.pop_back();
		}
	}
	if (IsValid(i, j, n,'L')) {
		int ti = i;
		int tj = j - 1;
		if (maz[ti][tj] == 1 && !inCurPath(ti, tj, path)) {
			path.push_back({ ti,tj });
			dir.push_back('L');
			Dfs(ti, tj, n, maz, path, dir,i, j, paths);
			dir.pop_back();
			path.pop_back();
		}
	}

	if (IsValid(i, j, n, 'R')) {
		int ti = i;
		int tj = j + 1;
		if (maz[ti][tj] == 1 && !inCurPath(ti, tj, path)) {
			path.push_back({ ti,tj });
			dir.push_back('R');
			Dfs(ti, tj, n, maz, path, dir, i, j, paths);
			dir.pop_back();
			path.pop_back();
		}
	}

	if (IsValid(i, j,n, 'U')) {
		int ti = i - 1;
		int tj = j;
		if (maz[ti][tj] == 1 && !inCurPath(ti, tj, path)) {
			path.push_back({ ti,tj });
			dir.push_back('U');
			Dfs(ti, tj, n, maz, path, dir, i, j, paths);
			dir.pop_back();
			path.pop_back();
		}
	}

	

}

/*The function returns a sorted array of strings which represents
the directions mouse will take to reach the destination.
You are required to complete the below method. */
vector<string> printPath(int m[MAX][MAX], int n)
{
	vector<string> paths;
	vector<pair<int, int>> curPath;
	vector<char> dir;
	curPath.push_back({ 0,0 });
	Dfs(0, 0, n, m, curPath, dir, -1, -1, paths);
	return paths;
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
	while (t--) {
		int n;
		cin >> n;

		int m[100][100];
		for (int i = 0; i<n; i++)
		{
			for (int j = 0; j<n; j++)
			{
				cin >> m[i][j];
			}
		}

		vector<string> res = printPath(m, n);
		for (int i = 0; i<res.size(); i++)
			cout << res[i] << " ";
		cout << endl;
	}
	return 0;
}