// GraphsCpp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <tuple>
#include <iostream>
#include <vector>;

using namespace std;

int spanningTree(std::vector<std::pair<int, int>> g[], int MAX);
const int m = 1e4 + 5;
int main()
{
	//1 2 5 /2 3 3  /1 3 1

	
	pair<int, int> p12{5,2};
	pair<int, int> p13{ 1,3 };
	pair<int, int> p23{ 3,3 };
	pair<int, int> p21{ 5,1 };
	pair<int, int> p31{ 1,1 };
	pair<int, int> p32{ 3,2 };

	vector<pair<int, int>> v1{ p12, p13 };
	vector<pair<int, int>> v2{ p21, p23 };
	vector<pair<int, int>> v3{ p31, p32 };
	vector<pair<int, int>> g[4];// {, v1, v2};
	g[1] = v1;
	g[2] = v2;
	g[3] = v3;

	cout << spanningTree(g,m) << endl;

	int i;
	cin >> i;

	return 0;
}

