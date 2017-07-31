// MirrorOfNode.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
// C program to find the mirror Node in Binary tree
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

/* A binary tree Node has data, pointer to left child
and a pointer to right child */
struct Node
{
	int key;
	struct Node* left, *right;
};
int counter = 0;
int target = 0;
struct Node *ptr = NULL;
// create new Node and initialize it
struct Node* newNode(int key)
{
	struct Node* n = new Node();
	if (n != NULL)
	{
		n->key = key;
		n->left = NULL;
		n->right = NULL;
		return n;
	}
	else
	{
		printf("Memory allocation failed!");
		exit(1);
	}
}

/*
Please note that it's Function problem i.e.
you need to write your solution in the form Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


bool TryfindPath(Node* node, vector<char>& s, int& target) {
	if (node == nullptr)
		return false;

	if (node->key == target)
		return true;

	s.push_back('L');
	auto foundLeft = TryfindPath(node->left, s, target);
	if (foundLeft)
		return true;
	s.pop_back();

	s.push_back('R');

	auto foundRight = TryfindPath(node->right, s, target);
	if (foundRight)
		return true;

	s.pop_back();

	return false;

}

// recursive function to find mirror of Node
int findMirrorRec(int target, struct Node* left,
	struct Node* right)
{
	if (left->key == target)
		return right->key;

	if (right->key == target)
		return left->key;

	vector<char> path;
	bool found = TryfindPath(left, path, target);
	Node* searchNode = nullptr;
	if (found) {
		searchNode = right;
	}
	else
	{
		path.clear();
		found = TryfindPath(right, path, target);
		if (found)
			searchNode = left;
	}
	int res = -1;
	if (searchNode != nullptr) {
		int n = path.size();
		int i = 0;
		while (i<n && searchNode != nullptr) {
			if (path[i] == 'L')
				searchNode = searchNode->right;
			else
				searchNode = searchNode->left;
			i++;
		}
	}

	if (searchNode != nullptr)
		res = searchNode->key;

	return res;

	// Your code goes here
}

// interface for mirror search
int findMirror(struct Node* root, int target)
{
	if (root == NULL)
		return 0;
	if (root->key == target)
		return target;
	return findMirrorRec(target, root->left, root->right);
}
void insert(struct Node *root, int n1, int n2, char lr)
{
	if (root == NULL)
		return;
	if (root->key == n1)
	{
		switch (lr)
		{
		case 'L': root->left = newNode(n2);
			break;
		case 'R': root->right = newNode(n2);
			break;
		}
	}
	else
	{
		insert(root->left, n1, n2, lr);
		insert(root->right, n1, n2, lr);
	}
}
/*void Inorder(struct Node* root)
{

if(counter==0)
{
cin>>target;
counter++;
}

if(root==NULL)
return ;

Inorder(root->left);

if(root->key==target)
ptr=root;

Inorder(root->right);
}*/
// Driver program to test above functions
int main()
{
#if _DEBUG
	std::ifstream ins("input.txt");
	std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	std::cin.rdbuf(ins.rdbuf()); //redirect std::cin to in.txt!
#endif
	/* Let us construct the tree shown in above diagram */
	int t, k;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		struct Node *root = NULL;
		while (n--)
		{
			char lr;
			int n1, n2;
			cin >> n1 >> n2;
			cin >> lr;
			if (root == NULL)
			{
				root = newNode(n1);
				switch (lr) {
				case 'L': root->left = newNode(n2);
					break;
				case 'R': root->right = newNode(n2);
					break;
				}
			}
			else
			{
				insert(root, n1, n2, lr);
			}
		}
		// Inorder(root);
		//Node * target =ptr;
		//printkdistanceNode(root, target, k);
		//cout<<endl;
		cin >> target;
		counter = 0;
		int mirror = findMirror(root, target);

		if (mirror)
			printf("%d\n", mirror);
		else
			printf("-1\n");
	}
	return 0;
}

