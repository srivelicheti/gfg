// Trees.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <unordered_map>
#include <cmath>
using namespace std;

struct Node {
	int data;
	Node* left;
	Node* right;
};

Node* CreateTree(int e) {
	int i = 0;
	Node* root = nullptr;
	unordered_map<int, Node*> map{};
	for (int i = 0; i < e; i++)
	{
		int s1, s2;
		char dir;
		cin >> s1 >> s2 >> dir;
		Node* ns1;
		Node* ns2;
		if (map.find(s1) == map.end()) {
			ns1 = new Node{ s1 };
			map.insert({ s1,ns1 });
		}
		else {
			ns1 = map.find(s1)->second;
		}

		if (map.find(s2) == map.end()) {
			ns2 = new Node{ s2 };
			map.insert({s2,ns2});
		}
		else {
			ns2 = map.find(s2)->second;
		}

		if (dir == 'L') {
			ns1->left = ns2;
		}
		else {
			ns1->right = ns2;
		}
		if (i == 0) {
			root = ns1;
		}
	}
	return root;
}

int mod = pow(10, 9) + 7;

void accumulate(Node* n1, Node* n2, int& curSum) {
	if (n1 == nullptr || n2 == nullptr) return;
	curSum = (curSum + (n1->data * n2->data) % mod) % mod;

	accumulate(n1->left, n2->right, curSum);
	accumulate(n1->right, n2->left, curSum);
}

void SolveOne() {
	int e;
	cin >> e;
	auto root = CreateTree(e);
	int curSum = 0;
	accumulate(root->left, root->right, curSum);
	curSum = (curSum + (root->data * root->data) % mod) % mod;

	cout << curSum << endl;

}

int main()
{
#if _DEBUG
	std::ifstream ins("input.txt");
	std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	std::cin.rdbuf(ins.rdbuf()); //redirect std::cin to in.txt!
#endif

	int t;
	cin >> t;
	while (t--) {
		SolveOne();
	}
								 //code
	return 0;
}

