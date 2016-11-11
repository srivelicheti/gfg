// Cpp.BinaryTrees.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <algorithm>
#include <iostream>
#include <tuple>
#include <map>
using namespace ::std;

struct Node;


Node* cloneinternal(Node* nodeToClone, Node* parent, bool isLeftLink = true);
Node* clone(Node* root);
Node* clonestring();




int main()
{

	Node* cloned = clonestring();

	return 0;
}

