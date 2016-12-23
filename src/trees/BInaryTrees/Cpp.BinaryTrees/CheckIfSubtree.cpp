#include "stdafx.h"
#include <queue>


namespace CheckIfSubtree
{
	//O(N) Hint 
	/* Better Solution
	 * The idea is based on the fact that inorder and preorder/postorder uniquely identify a binary tree. Tree S is a subtree of T if both inorder and preorder traversals of S arew substrings of inorder and preorder traversals of T respectively.
		Following are detailed steps.
		1) Find inorder and preorder traversals of T, store them in two auxiliary arrays inT[] and preT[].
		2) Find inorder and preorder traversals of S, store them in two auxiliary arrays inS[] and preS[].
		3) If inS[] is a subarray of inT[] and preS[] is a subarray preT[], then S is a subtree of T. Else not.
	 */
	struct Node
	{
		int key;
		struct Node* left, *right;
	};

	bool isLeaf(Node* n1)
	{
		return n1->left == nullptr && n1->right == nullptr;
	}

	bool IsEqualTree(Node* n1, Node* n2)
	{
		if (n1 == nullptr && n2 == nullptr)
			return true;
		else if ((n1 && !n2) || (n2 && !n1))
			return false;
		else if(n1->key ==n2->key && isLeaf(n1) && isLeaf(n2))
			return true;

		return n1->key == n2->key && IsEqualTree(n1->left, n2->left) && IsEqualTree(n1->right, n2->right);
	}

	/*you are required to
	complete this function */
	bool isSubtree(Node*  T1, Node * T2)
	{
		//do a BFS on T1 checking if each node is equal to root of T2, if equal then check if complete tree from that point is equal

		queue<Node*> queue{};
		queue.push(T1);
		bool isSubTree = false;
		while(!queue.empty())
		{
			auto curr = queue.front();
			queue.pop();
			if(curr->key == T2->key)
			{
				isSubTree = IsEqualTree(curr, T2);
				if(isSubTree)
					break;
			}
			if (curr->left)
				queue.push(curr->left);

			if (curr->right)
				queue.push(curr->right);

		}

		return isSubTree;
	}

	void CheckIfSubtree_main()
	{

	}
}
