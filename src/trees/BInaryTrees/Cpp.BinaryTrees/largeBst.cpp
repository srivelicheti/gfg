#include "stdafx.h"
#include <tuple>
#include <algorithm>
#include <stdio.h>
#include <iostream>
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

static int _currentMaxHeight = 0;
tuple<int, int, int> largeBstInternal(Node* n);

int largestBst(Node* node)
{
	_currentMaxHeight = 0;
	if (node == nullptr)
		return 0;
	auto size = largeBstInternal(node);

	return _currentMaxHeight;
}

tuple<int,int,int> largeBstInternal(Node* n)
{
	if (n == nullptr)
		return make_tuple(0, -1, -1);

	auto left = largeBstInternal(n->left);

	auto leftMin = get<1>(left);
	auto leftMax = get<2>(left);
	auto isLeftValid = (leftMin == -1 || leftMin <= n->data) &&
		(leftMin == -1 || leftMax <= n->data);

	auto minLeft = !isLeftValid ? -1 :
		(leftMin != -1 ? leftMin : (leftMax != -1 ? leftMax : (n->data)));

	auto right = largeBstInternal(n->right);

	auto rightMin = get<1>(right);
	auto rightMax = get<2>(right);
	auto isrightValid = (rightMin == -1 || rightMin > n->data) &&
		(rightMin == -1 || rightMax > n->data);

	auto maxRight = !isrightValid ? -1 :
		(rightMax != -1 ? rightMax : (rightMin != -1 ? rightMin : (n->data)));


	auto isBinary = isrightValid && isLeftValid;

	auto currentTreeHeight = !isBinary || get<0>(left) == -1 || get<0>(right) == -1 
		? -1 : get<0>(left) + get<0>(right) + 1;

	_currentMaxHeight = max(_currentMaxHeight, currentTreeHeight);

	return make_tuple(currentTreeHeight, minLeft, maxRight);

}