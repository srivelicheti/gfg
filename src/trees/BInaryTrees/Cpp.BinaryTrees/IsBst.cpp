
#include "stdafx.h"
#include <tuple>
#include <algorithm>
using namespace ::std;
#ifndef NODE_DEFINED
#define NODE_DEFINED
struct Node
{
	int data;
	struct Node* left;
	struct Node* right;
};	
#endif


tuple<bool, int, int> isBstInternal(Node* node, Node* parent)
{
	if (node == nullptr && parent != nullptr)
		return make_tuple(true, parent->data, parent->data);
	else if (node == nullptr)
		return make_tuple(false, -1, -1);

	auto left = isBstInternal(node->left, node);
	auto isLeftChildBinary = get<0>(left);
	auto right = isBstInternal(node->right, node);
	auto isRightChildTreeBinary = get<0>(right);

	if (!isLeftChildBinary || !isRightChildTreeBinary)
		return make_tuple(false, -1, -1);

	auto leftMin = get<1>(left);
	auto leftMax = get<2>(left);

	auto rightMin = get<1>(right);
	auto rightMax = get<2>(right);

	bool isBinary =
		node->left == nullptr ||
		(leftMin <= node->data && leftMax <= node->data);
	isBinary = isBinary &&
		(node->right == nullptr ||
		(rightMin > node->data && rightMax > node->data));

	auto minVal = min(min(leftMin, leftMax), node->data);
	auto maxVal = max(max(rightMin, rightMax), node->data);

	return make_tuple(isBinary, minVal, maxVal);
	//auto 


}

bool isBST(Node* root) {

	auto bst = isBstInternal(root, root);
	return get<0>(bst);
}

