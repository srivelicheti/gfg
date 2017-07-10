// PreOrderBstValCPP.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <limits>
#include <fstream>
using namespace std;

struct Node
{
	char data;
	struct Node* left;
	struct Node* right;
};

Node* ConstructTree(vector<int>& preArr, int& n ,int& preIndex, int min ,int max ) {
	if (preIndex >= n)
		return nullptr;

	Node* root = nullptr;

	auto data = preArr[preIndex];
	if (data > min && data < max) {
		preIndex++;
		root = new Node();
		root->data = data;
		root->left = ConstructTree(preArr, n, preIndex, min, data);
		root->right = ConstructTree(preArr, n, preIndex, data, max);
	}

	return root;
}

void SolveOne() {
	int n;
	cin >> n;
	int i = 0;
	vector<int> preArr(n);
	while (i < n) {
		cin >> preArr[i];
		i++;
	}
	int preIndex = 0;
	int minI = numeric_limits<int>::min();
	int maxI = numeric_limits<int>::max();
	Node* root = ConstructTree(preArr, n, preIndex, minI, maxI);
	if (preIndex != n)
		cout << 0 << endl;
	else
		cout << 1 << endl;
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
    return 0;
}

