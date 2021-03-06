// LargestIndependentSubsetInBinaryTree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


#include <stdio.h>
#include <stdlib.h>
#include <map>
#include <iostream>
#include <fstream>

#include <algorithm>
#include <unordered_map>
using namespace std;

/* A binary tree node has data, pointer to left child and a pointer to
right child */
struct Node
{
	int data;
	struct Node *left, *right;
};

// A utility function to create a node
struct Node* newNode(int data)
{
	struct Node* temp = (struct Node *) malloc(sizeof(struct Node));
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

// you are required to complete this function
// function should return the size of the 
// Largest Independent set in the tree


int LISSImpl(struct Node *node, std::unordered_map<Node*, int>& map) {
	if (node == nullptr) return 0;
	if (node->left == nullptr && node->right == nullptr) return 1;
	auto cached = map.find(node);
	if (cached != map.end()) {
		return cached->second;
	}
	//considering current node
	int nmax = 1;
	if (node->left != nullptr) {
		nmax += LISSImpl(node->left->left, map);
		nmax += LISSImpl(node->left->right, map);
	}
	if (node->right != nullptr) {
		nmax += LISSImpl(node->right->left, map);
		nmax += LISSImpl(node->right->right, map);
	}

	int tMax = LISSImpl(node->left, map) + LISSImpl(node->right, map);
	int fmax = std::max(nmax, tMax);
	map.insert({ node,fmax });

	return fmax;

}

int LISS(struct Node *root)
{

	std::unordered_map<Node*, int> map;
	return LISSImpl(root, map);
	//Code here
}

/* Driver program to test size function*/
int main()
{

#if _DEBUG
	std::ifstream ins("input.txt");
	std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	std::cin.rdbuf(ins.rdbuf()); //redirect std::cin to in.txt!
#endif

	int t;
	struct Node *child;
	cin >> t;
	while (t--)
	{
		map<int, Node*> m;
		int n;
		cin >> n;
		struct Node *root = NULL;
		while (n--)
		{
			Node *parent;
			char lr;
			int n1, n2;
			cin >> n1 >> n2 >> lr;
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
		cout << LISS(root) << endl;
	}
	return 0;
}


