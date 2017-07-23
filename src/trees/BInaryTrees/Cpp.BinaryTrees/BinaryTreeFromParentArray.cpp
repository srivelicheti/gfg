#include "stdafx.h"
#include <vector>
#include <algorithm>

namespace BinaryTreeFromParentArray
{

	struct Node
	{
		int data;
		Node* left, *right;
	};

	/*  Function which returns the  root of
	the constructed binary tree. */
	Node *createTree(int parent[], int n)
	{
		if (n == 0)
			return  nullptr;
		Node** nodeArr = new Node*[n] {nullptr};

		Node* root = nullptr;

		for (int i = 0; i < n; ++i)
		{

			if (parent[i] != -1)
			{

				auto pNode = nodeArr[parent[i]];

				if (pNode == nullptr)
				{
					pNode = new Node{ parent[i],nullptr,nullptr };
					nodeArr[parent[i]] = pNode;
				}

				auto childNode = nodeArr[i];
				if (childNode == nullptr)
					childNode = new Node{ i,nullptr,nullptr };

				if (pNode->left == nullptr)
					pNode->left = childNode;
				else if (pNode->right == nullptr)
					pNode->right = childNode;
				nodeArr[i] = childNode;
			}
			else
			{
				if (nodeArr[i] == nullptr)
					nodeArr[i] = new Node{ i,nullptr,nullptr };
				root = nodeArr[i];
			}

		}

		delete nodeArr;
		return root;
		// Your code here
	}


	vector<int> result;
	void printGivenLevel(Node* root, int level)
	{
		if (root == NULL)
			return;
		if (level == 1)
			result.push_back(root->data);
		else if (level > 1)
		{
			printGivenLevel(root->left, level - 1);
			printGivenLevel(root->right, level - 1);
		}
	}

	int height(struct Node* node)
	{
		if (node == NULL)
			return 0;
		else
		{

			int lheight = height(node->left);
			int rheight = height(node->right);


			if (lheight > rheight)
				return(lheight + 1);
			else return(rheight + 1);
		}
	}


	void printLevelOrder(struct Node* root)
	{
		int h = height(root);
		int i;
		for (i = 1; i <= h; i++) {
			result.clear();
			printGivenLevel(root, i);
			sort(result.begin(), result.end());
			for (int i = 0; i < result.size(); i++)
				cout << result[i] << " ";
		}
	}



	Node *newNode(int key)
	{
		Node *temp = new Node;
		temp->data = key;
		temp->left = temp->right = NULL;
		return (temp);
	}





	Node *createTree(int parent[], int n);


	void inorder(Node *root)
	{
		if (root == NULL)
			return;
		inorder(root->left);
		cout << root->data << " ";
		inorder(root->right);
	}


	/* Driver program to test above function*/
	void BinaryTreeFromParentArray_main()
	{
		int T, i, n, l, k;

		/*reading input stuff*/
		cin >> T;

		while (T--) {
			int N;
			cin >> N;
			int* a = new int[N];
			for (int i = 0; i < N; i++)
				cin >> a[i];

			struct Node *res = createTree(a, N);
			// print(res);
			//  memset(result,0,100);
			printLevelOrder(res);


			cout << endl;

		}


	}




}
