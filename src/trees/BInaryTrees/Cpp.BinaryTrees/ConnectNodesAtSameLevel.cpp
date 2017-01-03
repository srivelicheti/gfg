#include "stdafx.h"
#include "queue"


namespace ConnectNodesAtSameLevel
{
	struct Node
	{
		int data;
		Node *left, *right;
		Node *nextRight;  // This has garbage value in input trees
	};

	// Should set the nextRight for all nodes
	void connect(Node *p)
	{
		if(p == nullptr)
			return;

		queue<pair<Node*,int>> q;
		pair<Node*, int> prev ={nullptr,-1};
		p->nextRight = nullptr;
		q.push({ p,0 });
		while(!q.empty())
		{
			auto curr = q.front();
			q.pop();

			int currentLevel = curr.second;
			auto currNode = curr.first;
			currNode->nextRight = nullptr;
			if (currNode->left)
				q.push({ currNode->left,currentLevel + 1 });
			if (currNode->right)
				q.push({ currNode->right,currentLevel + 1 });

			if (prev.first != nullptr)
			{
				if (prev.second == currentLevel)
					prev.first->nextRight = currNode;
				else
					prev.first->nextRight = nullptr;
			}

			prev = curr;

		}

		// Your Code Here
	}

	void ConnectNodesAtSameLevel_main()
	{

	}
}