#include "stdafx.h"
#include <tuple>
#include <algorithm>
#include <stdio.h>
#include <iostream>
using namespace ::std;


struct Node
{
	int data;
	struct Node* left;
	struct Node* right;
};

static int _currentMaxHeight = 0;
tuple<int, bool> GetRightMaxBTreeSize(Node* child, Node* parent, int currentMax, bool isLeftSubtree);
tuple<int, bool> GetLeftMaxBTreeSize(Node* child, Node* parent, int currentMax, bool isLeftSubtree);

int largestBst(Node* node)
{
	_currentMaxHeight = 0;
	if (node == nullptr)
		return 0;

	/*auto left = GetLeftMaxBTreeSize(node->left, node, node->data, true);
	auto right = GetRightMaxBTreeSize(node->right, node, node->data, false);

	auto totalBinaryTreeHeight = (left == -1 || right == -1) ? 1 : (left + right + 1);*/


	auto leftTuple = GetLeftMaxBTreeSize(node->left, node, node->data, true);
	auto left = get<0>(leftTuple);

	auto rightTuple = GetRightMaxBTreeSize(node->right, node, node->data, false);

	auto right = get<0>(rightTuple);

	auto isFullLeftBinaryTree = get<1>(leftTuple);
	auto isFullRightBinaryTree = get<1>(rightTuple);

	auto totalBinaryTreeHeight = (left == -1 || right == -1 || !isFullLeftBinaryTree || !isFullRightBinaryTree) ? -1 : (left + right + 1);

	_currentMaxHeight = max(_currentMaxHeight, totalBinaryTreeHeight);


	return _currentMaxHeight;

}

tuple<int, bool> GetLeftMaxBTreeSize(Node* child, Node* parent, int currentMax, bool isLeft)
{
	if (child == nullptr)
		return make_tuple(0, true);

	auto isBinaryTree = child->data <= parent->data;

	auto isBinaryTreeWithParent = (isLeft ? child->data <= currentMax : child->data > currentMax);

	auto leftTuple = GetLeftMaxBTreeSize(child->left, child, parent->data, true);
	auto left = get<0>(leftTuple);

	auto rightTuple = GetRightMaxBTreeSize(child->right, child, parent->data, true);

	auto right = get<0>(rightTuple);

	auto isFullLeftBinaryTree = get<1>(leftTuple);
	auto isFullRightBinaryTree = get<1>(rightTuple);

	auto totalBinaryTreeHeight = (left == -1 || right == -1) ? 0 : (left + right + 1);
	_currentMaxHeight = max(_currentMaxHeight, totalBinaryTreeHeight);


	auto height = isBinaryTree && isBinaryTreeWithParent ? totalBinaryTreeHeight : -1;

	return make_tuple(height, isBinaryTreeWithParent);


}

tuple<int, bool> GetRightMaxBTreeSize(Node* child, Node* parent, int currentMax, bool isLeft)
{
	if (child == nullptr)
		return make_tuple(0, true);

	auto isBinaryTree = child->data > parent->data;
	auto isBinaryTreeWithParent = (isLeft ? child->data <= currentMax : child->data > currentMax);
	auto leftTuple = GetLeftMaxBTreeSize(child->left, child, parent->data, false);
	auto left = get<0>(leftTuple);

	auto rightTuple = GetRightMaxBTreeSize(child->right, child, parent->data, false);

	auto right = get<0>(rightTuple);

	auto isFullLeftBinaryTree = get<1>(leftTuple);
	auto isFullRightBinaryTree = get<1>(rightTuple);

	auto totalBinaryTreeHeight = (left == -1 || right == -1 || !isFullLeftBinaryTree || !isFullRightBinaryTree) ? 1 : (left + right + 1);
	_currentMaxHeight = max(_currentMaxHeight, totalBinaryTreeHeight);

	auto height = isBinaryTree ? totalBinaryTreeHeight : -1;

	return std::make_tuple(height, isBinaryTreeWithParent);

}