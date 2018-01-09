// NAryMirror.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
using namespace std;

struct Node
{
	int data;
	vector<Node* > child;
};

bool checkNary(Node* n1, Node* n2)
{
	if (n1 == nullptr && n2 == nullptr)
		return true;

	if ((n1 != nullptr && n2 == nullptr) || (n1 == nullptr && n2 != nullptr))
		return false;

	if (n1->data != n2->data)
		return false;

	if (n1->child.size() != n2->child.size())
		return false;

	int i1 = 0;
	int i2 = n2->child.size() - 1;
	while(i2 >=0)
	{
		Node* c1 = (n1->child)[i1];
		Node* c2 = (n2->child)[i2];
		if (!checkNary(c1, c2))
			return false;
		i1++; i2--;
	}

	return true;

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
		int n, e;
		cin >> n >> e;

		int i = 0;
		Node* root1 = nullptr;
		unordered_map<int, Node*> map;
		while(i<e)
		{
			int u, v;
			cin >> u >> v;
			Node* pnode;
			auto found = map.find(u);
			if (found == map.end())
			{
				pnode = new Node();
				pnode->data = u;
				map.insert({ u,pnode });
			}
			else
				pnode = found->second;
			if (i == 0)
				root1 = pnode;
			Node* cnode;
			found = map.find(v);
			if (found == map.end())
			{
				cnode = new Node;
				cnode->data = v;
				map.insert({ v,cnode });
			}
			else
				cnode = found->second;

			pnode->child.push_back(cnode);
			i++;
		}

		i = 0;
		map.clear();
		Node* root2 = nullptr;
		while (i<e)
		{
			int u, v;
			cin >> u >> v;
			Node* pnode;
			auto found = map.find(u);
			if (found == map.end())
			{
				pnode = new Node;
				pnode->data = u;
				map.insert({ u,pnode });
			}
			else
				pnode = found->second;
			if (i == 0)
				root2 = pnode;
			Node* cnode;
			found = map.find(v);
			if (found == map.end())
			{
				cnode = new Node;
				cnode->data = v;
				map.insert({ v,cnode });
			}
			else
				cnode = found->second;

			pnode->child.push_back(cnode);
			i++;
		}

		cout << checkNary(root1, root2) << endl;

	}

		//code
		return 0;
}
