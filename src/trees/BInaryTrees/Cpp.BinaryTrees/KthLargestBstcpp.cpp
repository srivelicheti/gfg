#include "stdafx.h"
#include <iostream>

namespace KthLargestBst
{

	struct Node
	{
		int key;
		Node *left, *right;
	};

	/*Complete the function below*/


	Node* FindKthLargest(Node* n, int k, int& c)
	{
		if (n == nullptr)
			return nullptr;

		auto kthLargest = FindKthLargest(n->right, k, c);
		if (kthLargest != nullptr)
			return kthLargest;
		else
		{

			c++;
			if (c == k)
				return n;

			kthLargest = FindKthLargest(n->left, k, c);

			return kthLargest;
		}

	}

	void kthLargest(Node *root, int k)
	{
		int c = 0;
		auto l = FindKthLargest(root, k, c);
		if (l != nullptr)
			std::cout << l->key;
	}

	Node *newNode(int item)
	{
		Node *temp = new Node;
		temp->key = item;
		temp->left = temp->right = NULL;
		return temp;
	}

	Node* insert(Node* node, int key)
	{
		if (node == NULL) return newNode(key);
		if (key < node->key)
			node->left = insert(node->left, key);
		else if (key > node->key)
			node->right = insert(node->right, key);
		return node;
	}
	void KthLargest_main()
	{
		int t;
		std::cin >> t;
		while (t--)
		{
			Node *root = NULL;
			int n;
			std::cin >> n;
			int a;
			std::cin >> a;
			root = insert(root, a);
			for (int i = 0; i < n - 1; i++)
			{
				std::cin >> a;
				insert(root, a);
			}
			int k;
			std::cin >> k;
			kthLargest(root, k);
		}
		//return 0;
	}



}
