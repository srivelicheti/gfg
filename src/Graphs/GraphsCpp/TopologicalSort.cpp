#include "stdafx.h"
#include <vector>
#include <iostream>
#include <queue>
#include <stack>
#include <list>

using namespace std;

//http://www.practice.geeksforgeeks.org/problem-page.php?pid=700255


void DFS(vector<int> graph[], int currentNode ,int N, bool visited[], vector<int> &output)
{
	if(visited[currentNode])
		return;
	auto currentEdges = graph[currentNode];

	for (auto edge : currentEdges)
	{
		if(!visited[edge])
			DFS(graph, edge, N, visited,output);
	}
	visited[currentNode] = true;
	output.push_back(currentNode);
}

void reverse_graph(vector<int> graph[], int N, vector<int>* reverse_graph)
{
	//vector<int> reverse_graph[50];

	/*for (int i = 0; i < N; ++i)
	{
	reverse_graph[i] = vector<int>{};
	}*/

	for (int i = 0; i < N; ++i)
	{
		auto curr = graph[i];
		for (auto n : curr)
		{
			reverse_graph[n].push_back(i);
		}
	}

	//return reverse_graph;
}
/* You need to complete this function */
int * topoSort(vector<int> graph[], int N)
{
	vector<int> output;
	bool* visited = new bool[N]{false};
	int currentNode = 0;
	vector<int> reversed[50];
	reverse_graph(graph, N, reversed);
	while (currentNode < N) {
		DFS(reversed, currentNode, N, visited, output);
		currentNode++;
	}
	int* ret = new int[N];
	int i = 0;
	for (auto value : output)
	{
		ret[i] = value;
		i++;
	}
	delete visited;
	
	int* retu = new int[6]{ 4,5,2,1,3,0 };
	return ret;

}




vector<int> graph[10001];


int * topoSort(vector<int> graph[], int N);

int TopoSort_main()
{
	int T;
	cin >> T;
	while (T--)
	{
		memset(graph, 0, sizeof graph);
		int N, E;
		cin >> E >> N;
		for (int i = 0; i<E; i++)
		{
			int u, v;
			cin >> u >> v;
			graph[u].push_back(v);
		}

		int *res = topoSort(graph, N);

		bool valid = true;
		for (int i = 0; i<N; i++)
		{
			int n = graph[res[i]].size();
			for (int j = 0; j<graph[res[i]].size(); j++)
			{
				for (int k = i + 1; k<N; k++)
				{
					if (res[k] == graph[res[i]][j])
						n--;
				}
			}
			if (n != 0)
			{
				valid = false;
				break;
			}
		}

		/*
		for(int i=0;i<N;i++)
		cout<<res[i]<<" ";
		cout<<endl;
		*/

		if (valid == false)
			cout << 0 << endl;
		else
			cout << 1 << endl;

	}

	return 0;
}


//Better way to do 

class Graph
{
	int V; // No. of vertices'

		   // Pointer to an array containing adjacency listsList
	list<int> *adj;

	// A function used by topologicalSort
	void topologicalSortUtil(int v, bool visited[], stack<int> &Stack);
public:
	Graph(int V); // Constructor

				  // function to add an edge to graph
	void addEdge(int v, int w);

	// prints a Topological Sort of the complete graph
	void topologicalSort();
};

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w); // Add w to v’s list.
}

// A recursive function used by topologicalSort
void Graph::topologicalSortUtil(int v, bool visited[],
	stack<int> &Stack)
{
	// Mark the current node as visited.
	visited[v] = true;

	// Recur for all the vertices adjacent to this vertex
	list<int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i)
		if (!visited[*i])
			topologicalSortUtil(*i, visited, Stack);

	// Push current vertex to stack which stores result
	Stack.push(v);
}

// The function to do Topological Sort. It uses recursive 
// topologicalSortUtil()
void Graph::topologicalSort()
{
	stack<int> Stack;

	// Mark all the vertices as not visited
	bool *visited = new bool[V];
	for (int i = 0; i < V; i++)
		visited[i] = false;

	// Call the recursive helper function to store Topological
	// Sort starting from all vertices one by one
	for (int i = 0; i < V; i++)
		if (visited[i] == false)
			topologicalSortUtil(i, visited, Stack);

	// Print contents of stack
	while (Stack.empty() == false)
	{
		cout << Stack.top() << " ";
		Stack.pop();
	}
}
