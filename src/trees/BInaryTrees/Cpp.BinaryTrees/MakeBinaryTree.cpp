#include "stdafx.h"
#include <queue>

namespace MakeBinaryTree
{

	struct node
	{
		int data;
		struct node* next;
	};

	//The structure of TreeNode is as follows
	struct TreeNode
	{
		int data;
		TreeNode *left;
		TreeNode *right;
	};


	/*You are required to complete this method*/
	void convert(node *head, TreeNode * &root)
	{
		std::queue<TreeNode*> queue{};
		root = new TreeNode{ head->data };
		queue.push(root);
		auto curr = head->next;
		while(curr)
		{
			auto first = new TreeNode{ curr->data };
			TreeNode* second = nullptr;
			curr = curr->next;
			if (curr)
			{
				second = new TreeNode{ curr->data };
				curr = curr->next;
			}
			
			if(!queue.empty())
			{
				auto parent = queue.front();
				queue.pop();
				parent->left = first;
				parent->right = second;
			}

			queue.push(first);
			queue.push(second);
		}
	}

	void MakeBinaryTree_Main()
	{

	}
}
