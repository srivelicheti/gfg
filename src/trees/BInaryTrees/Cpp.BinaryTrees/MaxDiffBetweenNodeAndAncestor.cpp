#include "stdafx.h"
#include <algorithm>

//http://www.practice.geeksforgeeks.org/problem-page.php?pid=700227

namespace MaxDiffBetweenNodeAndAncestor
{

	struct Node
	{
		int data;
		struct Node* left, *right;
	};

	#include <limits>
	int calMaxDiff = 0;
	int DFS(Node* node)
	{
		if (node->left == nullptr && node->right == nullptr)
			return node->data;

		int curr = node->data;
		int currentMin = curr;
		if(node->left)
		{
			int leftMin = DFS(node->left);
			int diff = curr - leftMin;
			if (diff > calMaxDiff)
				calMaxDiff = diff;
			currentMin = min(leftMin, currentMin);
		}
		if(node->right)
		{
			int rightMin = DFS(node->right);
			int diff = curr - rightMin;
			if (diff > calMaxDiff)
				calMaxDiff = diff;

			currentMin = min(currentMin, rightMin);
		}

		return currentMin;
	}

	/* Your are required to
	complete this method*/
	
	int maxDiff(Node* root)
	{
		calMaxDiff = INT32_MIN;
		DFS(root);
		return calMaxDiff;
		// Your code here 
	}

	

	void MaxDiffBetweenNodeAndAncestor_main()
	{

	}
}