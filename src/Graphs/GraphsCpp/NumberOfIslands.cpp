#include "stdafx.h"
//#include <vector>
//#define MAX 1000  
//
//typedef std::pair<int, int> ipair;
//
////http://www.practice.geeksforgeeks.org/problem-page.php?pid=700273
//
//void AddIfPositive(std::vector<ipair> &adj, int ti, int tj, int N, int M , int (&Visited)[MAX][MAX])
//{
//	if (ti >= 0 && tj >= 0 && tj <= M && ti <= N && Visited[ti][tj] == 0)
//	{
//		adj.push_back({ ti,tj });
//	}
//}
//
//std::vector<ipair> GetAdjacentPairs(int i, int j, int N, int M , int (&Visited)[MAX][MAX])
//{
//	std::vector<ipair> adj;
//
//	int ti = -1;
//	int tj = -1;
//
//	ti = i - 1;
//	tj = j - 1;
//	AddIfPositive(adj, ti, tj, N, M, Visited);
//	ti = i - 1;
//	tj = j;
//	AddIfPositive(adj, ti, tj, N, M, Visited);
//
//	ti = i - 1;
//	tj = j + 1;
//	AddIfPositive(adj, ti, tj, N, M, Visited);
//
//	ti = i;
//	tj = j - 1;
//	AddIfPositive(adj, ti, tj, N, M, Visited);
//
//	ti = i;
//	tj = j + 1;
//	AddIfPositive(adj, ti, tj, N, M, Visited);
//
//	ti = i + 1;
//	tj = j - 1;
//	AddIfPositive(adj, ti, tj, N, M, Visited);
//
//	ti = i + 1;
//	tj = j;
//	AddIfPositive(adj, ti, tj, N, M, Visited);
//
//	ti = i + 1;
//	tj = j + 1;
//	AddIfPositive(adj, ti, tj, N, M, Visited);
//	
//	return adj;
//
//}
//
//void MarkAdjacentAsCommplete(int(A)[MAX][MAX], int(&Visited)[MAX][MAX], int i, int j, int N, int M)
//{
//	if (A[i][j] == 1)
//	{
//		auto adj = GetAdjacentPairs(i, j, N, M, Visited);
//		for (auto pair : adj)
//		{
//			Visited[pair.first][pair.second] = 1;
//			if (A[pair.first][pair.second] == 1)
//			{
//				MarkAdjacentAsCommplete(A, Visited, pair.first, pair.second, N, M);
//			}
//		}
//
//	}
//}
//
//int findIslands(int A[MAX][MAX], int N, int M)
//{
//	int Visited[MAX][MAX] = {0};
//
//	int numberOfIslands = 0;
//
//	for (int i = 0; i < N; ++i)
//	{
//		for (int j = 0; j < M; ++j)
//		{
//			if(A[i][j] == 0 || Visited[i][j] == 1)
//				continue;
//
//			if (A[i][j] == 1)
//			{
//				numberOfIslands++;
//				MarkAdjacentAsCommplete(A, Visited, i, j, N, M);
//			}
//		 
//		}
//	}
//
//	return numberOfIslands;
//}
//
//
//
//
//
//
