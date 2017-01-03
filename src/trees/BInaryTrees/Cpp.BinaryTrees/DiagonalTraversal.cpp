#include "stdafx.h"
#include <queue>

//http://www.practice.geeksforgeeks.org/problem-page.php?pid=700193

namespace DiagonalTraversal
{

	// A binary tree node
	struct Node
	{
		int data;
		Node* left, *right;
	};


	void diagonalPrint(Node *root)
	{
		// your code here
		queue<Node*> queue;

		queue.push(root);

		while(queue.size() > 0)
		{
			auto next = queue.front();
			queue.pop();

			while (next != nullptr)
			{
				cout << next->data << " ";
				if (next->left != nullptr)
					queue.push(next->left);
				next = next->right;
			}
		}
	}

	void DiagonalTraversal_main()
	{

	}
}