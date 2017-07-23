// MobileNumericKeypad.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
typedef unsigned long long ll;

vector<int> maps[] = { vector<int>{8,0},
vector<int>{2,4,1},
vector<int>{1,3,5,2},
vector<int>{2,6,3},
vector<int>{1,5,7,4},
vector<int>{2,4,6,8,5},
vector<int>{3,5,9,6},
vector<int>{4,8,7},
vector<int>{0,7,9,5,8},
vector<int>{6,8,9}
};

ll Solve(int n)
{
	ll** mem = new ll*[n + 1];
	for(int i = 0;i<n+1;i++)
	{
		mem[i] = new ll[10];
		if (i == 1)
		for(int j = 0;j<10;j++)
		{
			 // base case
				mem[i][j] = 1;
			
		}
	}

	for (int i = 2; i < n + 1; i++)
	{
		for(int j = 0;j<10;j++)
		{
			ll total = 0;
			for(auto b:maps[j])
			{
				total = total + mem[i - 1][b];
			}
			mem[i][j] = total;
		}
	}

	return mem[n][0] + mem[n][1] + mem[n][2] + mem[n][3] + mem[n][4] + mem[n][5] + mem[n][6] + mem[n][7] + mem[n][8] + +mem[n][9];
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

	while(t--)
	{
		int n;
		cin >> n;
		cout << Solve(n) << endl;

	}

		//code
	return 0;
}