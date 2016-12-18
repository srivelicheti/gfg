#include "stdafx.h"
#include <vector>
#include <array>
#include <unordered_set>
//#include <pair>
using namespace std;



int spanningTree(std::vector<std::pair<int,int>> g[] ,int MAX )
{
	int* consumed = new int[MAX] {0};
	int totalWeight = 0;
	consumed[0] = 1;
	unordered_set<int> visited{ };
	visited.insert(1);

	while(true)
	{
		int minWeight = -1;
		int selectedEdge = -1;
		for(auto k = visited.begin();k!=visited.end();++k)
		{
			auto i = *k;
			auto currentEdges = g[i];
			for (auto edge : currentEdges)
			{
				if (visited.find(edge.second) != visited.end())
					continue;
				if (minWeight == -1 || edge.first < minWeight)
				{
					minWeight = edge.first;
					selectedEdge = edge.second;
				}
			}
		}
		/*for (auto i : visited)
		{
			
		}*/
		if (minWeight == -1)
			break;
		totalWeight += minWeight;
		visited.insert(selectedEdge);
	}
	return totalWeight;

	//while(true)
	//{
	//	int minWeight = -1;
	//	int selectedEdge = -1;
	//	for (int i = 0; i < MAX; ++i)
	//	{
	//		if(consumed[i] == 0)
	//			continue;
	//		
	//		auto currentEdges = g[i+1];
	//		

	//		for (auto edge : currentEdges)
	//		{
	//			if(consumed[edge.second - 1] == 1 )
	//				continue;
	//			if(minWeight == -1 || edge.first < minWeight )
	//			{
	//				minWeight = edge.first;
	//				selectedEdge = edge.second - 1;
	//			}
	//		}
	//		
	//		
	//	}
	//	if (minWeight == -1)
	//		break;
	//	totalWeight += minWeight;
	//	consumed[selectedEdge] = 1;
	//	//--remaining;
	//}

	delete consumed;

	return totalWeight;

}

