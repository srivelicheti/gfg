// GraphsCpp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <tuple>
#include <iostream>
#include <vector>;
#include <array>

using namespace std;

#define MAX 1000



//int spanningTree(std::vector<std::pair<int, int>> g[], int MAX);
//const int m = 1e4 + 5;
//int main_old()
//{
//	//1 2 5 /2 3 3  /1 3 1
//
//	
//	pair<int, int> p12{5,2};
//	pair<int, int> p13{ 1,3 };
//	pair<int, int> p23{ 3,3 };
//	pair<int, int> p21{ 5,1 };
//	pair<int, int> p31{ 1,1 };
//	pair<int, int> p32{ 3,2 };
//
//	vector<pair<int, int>> v1{ p12, p13 };
//	vector<pair<int, int>> v2{ p21, p23 };
//	vector<pair<int, int>> v3{ p31, p32 };
//	vector<pair<int, int>> g[4];// {, v1, v2};
//	g[1] = v1;
//	g[2] = v2;
//	g[3] = v3;
//
//	cout << spanningTree(g,m) << endl;
//
//	int i;
//	cin >> i;
//
//	return 0;
//}

typedef std::pair<int, int> ipair;

//http://www.practice.geeksforgeeks.org/problem-page.php?pid=700273

void AddIfPositive(std::vector<ipair> &adj, int ti, int tj, int N, int M, int(&Visited)[MAX][MAX])
{
	if (ti >= 0 && tj >= 0 && tj <= M && ti <= N && Visited[ti][tj] == 0)
	{
		adj.push_back({ ti,tj });
	}
}

std::vector<ipair> GetAdjacentPairs(int i, int j, int N, int M, int(&Visited)[MAX][MAX])
{
	std::vector<ipair> adj;

	int ti = -1;
	int tj = -1;

	ti = i - 1;
	tj = j - 1;
	AddIfPositive(adj, ti, tj, N, M, Visited);
	ti = i - 1;
	tj = j;
	AddIfPositive(adj, ti, tj, N, M, Visited);

	ti = i - 1;
	tj = j + 1;
	AddIfPositive(adj, ti, tj, N, M, Visited);

	ti = i;
	tj = j - 1;
	AddIfPositive(adj, ti, tj, N, M, Visited);

	ti = i;
	tj = j + 1;
	AddIfPositive(adj, ti, tj, N, M, Visited);

	ti = i + 1;
	tj = j - 1;
	AddIfPositive(adj, ti, tj, N, M, Visited);

	ti = i + 1;
	tj = j;
	AddIfPositive(adj, ti, tj, N, M, Visited);

	ti = i + 1;
	tj = j + 1;
	AddIfPositive(adj, ti, tj, N, M, Visited);

	return adj;

}

void MarkAdjacentAsCommplete(int(A)[MAX][MAX], int(&Visited)[MAX][MAX], int i, int j, int N, int M)
{
	if (A[i][j] == 1)
	{
		auto adj = GetAdjacentPairs(i, j, N, M, Visited);
		for (auto pair : adj)
		{
			Visited[pair.first][pair.second] = 1;
			if (A[pair.first][pair.second] == 1)
			{
				MarkAdjacentAsCommplete(A, Visited, pair.first, pair.second, N, M);
			}
		}

	}
}

int findIslands(int A[MAX][MAX], int N, int M)
{
	int Visited[MAX][MAX] = { 0 };

	int numberOfIslands = 0;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (A[i][j] == 0 || Visited[i][j] == 1)
				continue;

			if (A[i][j] == 1)
			{
				numberOfIslands++;
				MarkAdjacentAsCommplete(A, Visited, i, j, N, M);
			}

		}
	}

	return numberOfIslands;
}
int main() {
	// your code goes here
	int T;
	cin >> T;

	int A[MAX][MAX];
	while (T--)
	{
		int N, M;
		cin >> N >> M;
		memset(A, 0, sizeof A);
		for (int i = 0; i<N; i++)
			for (int j = 0; j<M; j++)
				cin >> A[i][j];
		cout << findIslands(A, N, M) << endl;
	}
	return 0;
}

