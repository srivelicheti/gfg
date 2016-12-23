#include "stdafx.h"
#include <queue>
#include <map>

//http://www.practice.geeksforgeeks.org/problem-page.php?pid=700308

namespace PrintTreeInZigag
{
	struct Node
	{
		int data;
		Node *left, *right;
	};

	/* Function to print nodes of extreme corners
	of each level in alternate order */
	void printExtremeNodes(Node* root)
	{
		queue<pair<Node*, int>> queue{};

		int prevLevel = 1;
		queue.push({ root,1 });
		Node* prev = nullptr;
		while (!queue.empty())
		{
			auto temp = queue.front();
			auto curr = temp.first;
			auto currLevel = temp.second;
			queue.pop();
			if (currLevel != prevLevel && currLevel % 2 == 0)
			{
				cout << prev->data << " ";
				cout << curr->data << " ";
			}
			if (curr->left)
				queue.push({ curr->left,currLevel + 1 });
			if (curr->right)
				queue.push({ curr->right,currLevel + 1 });

			prev = curr;
			prevLevel = currLevel;
		}
		//If there is only one node we will not have printed head
		if (prevLevel % 2 == 1)
		{
			cout << prev->data;
		}

		cout << endl;
	}





	/* Helper function that allocates a new node with the
	given data and NULL left and right pointers. */
	Node* newNode(int data)
	{
		Node* node = new Node;
		node->data = data;
		node->right = node->left = NULL;
		return node;
	}

	/* Function to print nodes of extreme corners
	of each level in alternate order */


	/* Driver program to test above functions*/
	void PrintTreeInZigag_main()
	{
		int t;
		scanf_s("%d\n", &t);
		while (t--)
		{
			map<int, Node*> m;
			int n;
			scanf_s("%d\n", &n);
			Node *root = NULL;
			while (n--)
			{
				Node *parent;
				char lr;
				int n1, n2;
				scanf_s("%d %d %c", &n1, &n2, &lr);
				//  cout << n1 << " " << n2 << " " << (char)lr << endl;
				if (m.find(n1) == m.end())
				{
					parent = newNode(n1);
					m[n1] = parent;
					if (root == NULL)
						root = parent;
				}
				else
					parent = m[n1];

				Node *child = newNode(n2);
				if (lr == 'L')
					parent->left = child;
				else
					parent->right = child;
				m[n2] = child;
			}
			printExtremeNodes(root);
			cout << endl;

		}
//		return 0;
	}
}
