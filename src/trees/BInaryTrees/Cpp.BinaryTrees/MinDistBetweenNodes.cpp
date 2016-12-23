#include "stdafx.h"
#include <map>

namespace MinDistBetweenNodes
{
	// A binary tree node
	struct Node
	{
	int data;
	struct Node* left, * right;
	}; 

	int aFound = -1;
	int bFound = -1;

	int calMinDist = -1;

	bool DFS(Node* n, int &a, int &b, int level)
	{
		if(n == nullptr)
			return false;
		bool foundAtThisLevel = n -> data == a || n->data == b;
		if (n->data == a)
			aFound = level;
		if (n->data == b)
			bFound = level;

		bool foundInLeft = false;
		bool foundInRight = false;
		if(aFound == -1 || bFound == -1)
		{
			if (n->left)
				foundInLeft = DFS(n->left, a, b, level + 1);

			if (n->right)
				foundInRight = DFS(n->right, a, b, level + 1);

			if ((foundInLeft && foundInRight) || (foundAtThisLevel && (foundInLeft||foundInRight)))
			{
				calMinDist = abs(aFound - level) + abs(bFound - level);
			}
		}

		return foundAtThisLevel || foundInLeft || foundInRight;
	}

	/* Should return minimum distance between a and b
	in a tree with given root*/
	int findDist(Node* root, int a, int b)
	{
		aFound = -1;
		bFound = -1;
		calMinDist = -1;
		DFS(root, a, b, 1);

		return calMinDist;
		// Your code here 
	}
	struct Node* newNode(int data)
	{
		struct Node* node = (struct Node*)
			malloc(sizeof(struct Node));
		node->data = data;
		node->left = NULL;
		node->right = NULL;

		return(node);
	}

	


	/* Driver program to test size function*/
	void MinDistBetweenNodes_main()
	{
		int t;
		struct Node *child;
		scanf_s("%d\n", &t);
		while (t--)
		{
			map<int, Node*> m;
			int n;
			scanf_s("%d\n", &n);
			struct Node *root = NULL;
			if (n == 1)
			{
				int a;
				cin >> a;
				cout << a << endl;
			}
			else {
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

					child = newNode(n2);
					if (lr == 'L')
						parent->left = child;
					else
						parent->right = child;
					m[n2] = child;
				}
				int a, b;
				cin >> a >> b;

				cout << findDist(root, a, b) << endl;

			}
		}
		//return 0;
	}

	

	/*void MinDistBetweenNodes_main()
	{
		
	}*/
}
