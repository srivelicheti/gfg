// KnightWalk.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <queue>
#include <tuple>
using namespace std;
//
//const int mx[8] = { -1, 1, 2,2,1,-1,-2,-2 };
//const int my[8] = { -2,-2,-1,1,2, 2, 1,-1 };


const int mx[8] = { -1,-2,-2,-1,1,2, 2,1 };
const int my[8] = { -2,-1, 1, 2,2,1,-1,-2};

bool isSafe(bool** ch, int x, int y, int& n, int& m) {
	if (x >= 0 && x < n && y >= 0 && y<m && !ch[x][y])
		return true;

	return false;
}

void SolveOne() {
	int n, m;
	cin >> n >> m;

	auto ch = new bool*[n];

	for (int i = 0; i<n; i++) {
		ch[i] = new bool[m];
		for (int j = 0; j<m; j++) {
			ch[i][j] = false;
		}
	}
	int sx, sy, dx, dy;
	cin >> sx >> sy >> dx >> dy;
	sx--; sy--; dx--; dy--;
	queue<tuple<int, int, int>> q;

	q.push(std::make_tuple(sx, sy, 0));
	ch[sx][sy] = true;
	int fsteps = 0;
	bool found = false;
	while (!q.empty() && !found) {
		auto cur = q.front();
		q.pop();
		int x = get<0>(cur);
		int y = get<1>(cur);
		int steps = get<2>(cur);
		for (int i = 0; i<8; i++) {
			int nx = x + mx[i];
			int ny = y + my[i];
			if (isSafe(ch, nx, ny, n, m)) {
				if (nx == dx && ny == dy) {
					fsteps = steps + 1;
					found = true;
					break;
				}
				ch[nx][ny] = true;
				q.push(make_tuple(nx, ny, steps + 1));
			}

		}

	}
	if (found)
		cout << fsteps << endl;
	else
		cout << -1 << endl;

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

