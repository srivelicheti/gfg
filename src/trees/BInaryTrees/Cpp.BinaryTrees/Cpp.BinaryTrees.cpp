// Cpp.BinaryTrees.cpp : Defines the entry point for the console application.


#include "stdafx.h"
#include <algorithm>
#include <iostream>
#include <tuple>
#include <map>
#include <string>
#include <stdio.h>
#include <vector>

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

Node* GetIfInMapElseAdd(map<int, Node*>& map, int key);
Node* createNodeFromString(string str);
bool isBST(Node* root);
unsigned int split(const std::string &txt, vector<std::string> &strs, char ch);

int main()
{

	
	Node* node = nullptr; // createNodeFromString("20 10 L 10 5 L 5 1 L 1 50 R");
	cout << isBST(node);
	return 0;
}

vector<string> splitStrings;
Node* createNodeFromString(string str)
{
	map<int, Node*> map;

	vector<string> splitStrings;
	split(str, splitStrings, ' ');
	vector<string>::iterator it;
	auto p = GetIfInMapElseAdd(map, stoi(splitStrings[0]));
	if (splitStrings.size() > 1) {
		for (it = splitStrings.begin(); it < splitStrings.end();)
		{
			auto parent = GetIfInMapElseAdd(map, stoi(*it));
			++it;
			//++it;
			auto child = GetIfInMapElseAdd(map, stoi(*it));
			++it;
			//++it;

			if (*it == "L " || *it == "L")
			{
				parent->left = child;
			}
			else
				parent->right = child;

			++it;
			//++it;

		}
	}

	return p;
}

unsigned int split(const std::string &txt, vector<std::string> &strs, char ch)
{
	unsigned int pos = txt.find(ch);
	unsigned int initialPos = 0;
	strs.clear();

	// Decompose statement
	while (pos != std::string::npos) {
		strs.push_back(txt.substr(initialPos, pos - initialPos + 1));
		initialPos = pos + 1;

		pos = txt.find(ch, initialPos);
	}

	// Add the last one
	strs.push_back(txt.substr(initialPos, std::min(pos, txt.size()) - initialPos + 1));

	return strs.size();
}

Node* GetIfInMapElseAdd(map<int,Node*>& map, int key)
{
	auto mapItr = map.find(key);
	if(mapItr == map.end())
	{
		auto n = new Node{ key,nullptr,nullptr };
		map[key] = n;
		return  n;
	}
	else
	{
		return  (*mapItr).second;
	}
}
