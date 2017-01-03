#include "stdafx.h"
#include <tuple>
//http://www.practice.geeksforgeeks.org/problem-page.php?pid=700209
namespace DeleteNodeFromBST
{

	struct Node {
		int data;
		Node * right, *left;
	};


	pair<Node*, Node*> FindNodeToDelete(Node* current, int x, Node* parent)
	{
		if (current->data == x)
			return{ current,parent };

		if (current->left != nullptr)
		{
			auto found = FindNodeToDelete(current->left, x, current);
			if (found.first != nullptr)
				return found;
		}

		if (current->right != nullptr)
		{
			auto found = FindNodeToDelete(current->right, x, current);
			if (found.first != nullptr)
				return found;
		}

		return{ nullptr,nullptr };
	}

	Node* deleteNode(Node* parent, Node* child)
	{
		bool isLeft = parent != nullptr && parent->left != nullptr && parent->left->data == child->data;

		Node* toBeReplacedWith = nullptr;
		if (child->left == nullptr && child->right == nullptr)
		{
			toBeReplacedWith = nullptr;
		}

		else if (child->left == nullptr && child->right != nullptr)
		{
			toBeReplacedWith = child->right;

		}
		else if (child->right == nullptr && child->left != nullptr)
		{
			toBeReplacedWith = child->left;

		}
		else {


			Node * p1 = child;
			toBeReplacedWith = child->right;
			bool tempIsRight = true;
			while(toBeReplacedWith->left != nullptr)
			{
				p1 = toBeReplacedWith;
				toBeReplacedWith = toBeReplacedWith->left;
			}
			deleteNode(p1, toBeReplacedWith);
			toBeReplacedWith->right = child->right;
			toBeReplacedWith->left = child->left;
		}




		if (parent == nullptr)
		{
			return toBeReplacedWith;
		}
		else
		{
			if (isLeft)
				parent->left = toBeReplacedWith;
			else
				parent->right = toBeReplacedWith;
		}
		return parent;
	}

	Node * deleteNode(Node *root, int x)
	{
		if (root == nullptr)
			return root;

		auto toDelete = FindNodeToDelete(root, x, nullptr);

		if (toDelete.first != nullptr)
		{
			auto parent = toDelete.second;
			if (parent == nullptr)
				return deleteNode(parent, toDelete.first);
			else
			{
				if (parent->left != nullptr && parent->left->data == x)
					deleteNode(parent, toDelete.first);
				else
					deleteNode(parent, toDelete.first);
			}
		}

		return root;
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
		else if (val > (*tree)->data)
		{
			insert(&(*tree)->right, val);
		}
	}
	void inorder(Node *root)
	{
		if (root == NULL)
			return;
		inorder(root->left);
		cout << root->data << " ";
		inorder(root->right);
	}


	void DeleteNodeFromBST_main()
	{
		int T;
		cin >> T;
		while (T--)
		{
			Node *root;
			Node *tmp;
			root = nullptr;
			int N;
			cin >> N;
			for (int i = 0; i < N; i++)
			{
				int k;
				cin >> k;
				insert(&root, k);
			}
			int r;
			cin >> r;
			root = deleteNode(root, r);
			inorder(root);
			cout << endl;
		}
	}


}