#include "stdafx.h"
//#include <vector>
//#include <queue>
//#include <unordered_set>
//
//
//using namespace std;
//
//struct Node
//{
//	int from;
//	int to;
//	int weight;
//	int currentWeight;
//
//	Node(int x, int y, int w)
//	{
//		from = x;
//		to = y;
//		weight = w;
//		currentWeight = 1001;
//	}
//};
//
//
//struct comparator {
//	bool operator()(Node i, Node j) {
//		return i.currentWeight > j.currentWeight;
//	}
//};
//
//
//
//int spanningTreeWeight(std::vector<pair<int, int>> g[], int MAX)
//{
//	
//	vector<Node> input{};
//
//	for (int i = 1; i <= MAX; ++i)
//	{
//		try
//		{
//			if(g[i].size() == 0)
//				continue;
//		}
//		catch(...)
//		{
//			break;
//		}
//		auto currentEdges = g[i];
//		for (auto edge : currentEdges)
//		{
//			Node temp{ i,edge.second,edge.first };
//			if (i == 1)
//				temp.currentWeight = edge.first;
//			input.push_back(temp);
//			
//
//		}
//	}
//	comparator c{};
//	priority_queue<Node, vector<Node>, comparator> pq{ c,input };
//	
//	unordered_set<int> visisted{};
//	visisted.insert(1);
//
//    while(!pq.empty())
//    {
//		auto selectedEdge = pq.top();
//
//    }
//	/*for (auto node : min_heap)
//	{
//	}*/
//
//}
//
////void UpdatePqWithSelected()