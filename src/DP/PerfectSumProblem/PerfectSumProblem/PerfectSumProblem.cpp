// PerfectSumProblem.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

const int MAX = 10000;
int arr[MAX];
//static int mem[MAX][MAX];
void solve(vector<vector<int>>& mem,int n, int sum) {
	for (int i = 0; i <= n; i++)
		mem[0][i] = 1;

	for (int i = 1; i <= sum; i++) {
		mem[i][0] = 0;
	}

	for (int i = 1; i <= sum; i++) {
		for (int j = 1; j <= n; j++) {
			if (arr[j-1] > i) {
				mem[i][j] = mem[i][j - 1];
			}
			else {
				mem[i][j] = mem[i][j - 1] + mem[i - arr[j-1]][j - 1];
			}
		}
	}
	cout << mem[sum][n] << endl;
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
		int n;
		cin >> n;
		int i = 0;
		while (i < n) {
			cin >> arr[i];
			i++;
		}
		int sum;
		cin >> sum;
		vector<vector<int>> v(sum + 1, vector<int>(n+1));
		//memset(mem,-1)
		solve(v, n, sum);
	}
	//code
	return 0;
}
