#include "stdafx.h"
#include <stdio.h>
#include <string>
#include <algorithm>
#include <map>

using namespace ::std;
//
//#ifndef NODE_DEFINED
//#define NODE_DEFINED
//struct Node
//{
//	int data;
//	struct Node* left;
//	struct Node* right;
//	struct Node* random;
//};
//#endif
//
////struct Node
////{
////	int data;
////	struct Node* left;
////	struct Node* right;
////	
////};
//
//
//Node* cloneinternal(Node* nodeToClone, Node* parent, bool isLeftLink);
//Node* cloneTree(Node* tree);
//
//
//static map<int, Node*> nodesMap;
//
//Node* clonestring()
//{
//	
//	auto np1 = new Node{ 1 };
//	auto np5 = new Node{ 5 };
//	auto np3 = new Node{ 3,np1,np5 };
//	auto np8 = new Node{ 8 };
//	auto np6 = new Node{ 6,np3,np8 };
//	np1->random = np3;
//	np5->random = np6;
//
//	auto cloned = cloneTree(np6);
//
//	return cloned;
//}
//
//Node* cloneTree(Node* tree)
//{
//	nodesMap.clear();
//	return cloneinternal(tree, nullptr, false);
//}
//
//Node* cloneinternal(Node* nodeToClone , Node* parent, bool isLeftLink)
//{
//	if (nodeToClone == nullptr)
//		return nullptr;
//
//	auto clonedIterator = nodesMap.find(nodeToClone->data);
//	Node* cloned = nullptr;
//
//	if(clonedIterator == nodesMap.end())
//	{
//		cloned = new Node{ nodeToClone->data,nullptr,nullptr };
//		nodesMap[cloned->data] = cloned; // (cloned->data, cloned);
//	}
//	else {
//		cloned = (clonedIterator->second);
//	}
//	
//	if(parent != nullptr)
//	{
//		if (isLeftLink) parent->left = cloned;
//		else parent->right = cloned;
//	}
//	cloned->left = cloneinternal(nodeToClone->left, cloned, true);
//	cloned->right = cloneinternal(nodeToClone->right, cloned, false);
//
//	if(nodeToClone->random)
//	{
//		auto randomIterator = nodesMap.find(nodeToClone->random->data);
//
//		Node* random = randomIterator == nodesMap.end() ?
//			nullptr : randomIterator->second;
//
//		if(random == nullptr)
//		{
//			random = new Node{ nodeToClone->random->data , nullptr,nullptr };
//			nodesMap[random->data] = random;
//		}
//		cloned->random = random;
//	}
//
//	return  cloned;
//
//}
