// InOrdSucc.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
using namespace std;

struct Node {
	int data;
	struct Node * right, *left;
};

/*
Please note that it's Function problem i.e.
you need to write your solution in the form Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/*The structure of Node
struct Node {
int data;
Node * right, * left;
};*/
/* The below function should return the node which is
inorder successor of given node x. */

Node* inOrdSucc(Node* node, Node* x, Node*& prev) {
	if (node == nullptr)
		return nullptr;

	inOrdSucc(node->right, x, prev);
	if (x->data == node->data) {
		return prev;
	}
	
		prev = node;
		inOrdSucc(node->left, x, prev);
	
	return nullptr;

}

Node * inOrderSuccessor(Node *root, Node *x)
{
	Node* succ = nullptr;
	Node* prev = nullptr;
 succ =	inOrdSucc(root, x, prev);

	return succ;
	//Your code here
}
Node* search(Node* root, int key)
{
	// Base Cases: root is null or key is present at root
	if (root == NULL || root->data == key)
		return root;

	// Key is greater than root's key
	if (root->data < key)
		return search(root->right, key);

	// Key is smaller than root's key
	return search(root->left, key);
}

void insert(Node ** tree, int val)
{
	Node *temp = NULL;
	if (!(*tree))
	{
		temp = (Node *)malloc(sizeof(Node));
		temp->left = temp->right = NULL;
		temp->data = val;
		*tree = temp;
		return;
	}

	if (val < (*tree)->data)
	{
		insert(&(*tree)->left, val);
	}
	else if (val >(*tree)->data)
	{
		insert(&(*tree)->right, val);
	}

}

int getCountOfNode(Node *root, int l, int h)
{
	if (!root) return 0;
	if (root->data == h && root->data == l)
		return 1;
	if (root->data <= h && root->data >= l)
		return 1 + getCountOfNode(root->left, l, h) + getCountOfNode(root->right, l, h);
	else if (root->data < l)
		return getCountOfNode(root->right, l, h);
	else return getCountOfNode(root->left, l, h);
}

int main()
{
#if _DEBUG
	std::ifstream ins("input.txt");
	std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	std::cin.rdbuf(ins.rdbuf()); //redirect std::cin to in.txt!
#endif
	int T;
	cin >> T;
	while (T--)
	{
		Node *root;
		Node *tmp;
		//int i;
		root = NULL;
		int N;
		cin >> N;
		for (int i = 0; i<N; i++)
		{
			int k;
			cin >> k;
			insert(&root, k);
		}
		int k;
		cin >> k;
		Node* s = search(root, k);
		Node *R = inOrderSuccessor(root, s);
		if (R == NULL)
			cout << -1;
		else
			cout << R->data;
		cout << endl;
	}
}
