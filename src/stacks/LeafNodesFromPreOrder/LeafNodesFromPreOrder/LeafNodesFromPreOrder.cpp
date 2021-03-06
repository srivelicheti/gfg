// LeafNodesFromPreOrder.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <fstream>
#include <vector>
#include<stack>
using namespace std;
int main()
{
#if _DEBUG
	std::ifstream ins("input.txt");
	std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	std::cin.rdbuf(ins.rdbuf()); //redirect std::cin to in.txt!
#endif
	
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		vector<int>v(n);
		for (int i = 0; i < n; i++)
			cin >> v[i];
		vector<int> leafs;
		stack<int> s;
		s.push(v[0]);
		for (int i = 1; i < n; i++) {
			if (s.empty() || v[i] < s.top()) {
				s.push(v[i]);
			}
			else {
				auto top = s.top();
				s.pop();
				if (!s.empty() && top < s.top() && v[i] > s.top()) {
					leafs.push_back(top);
				}
				while (!s.empty() && s.top() < v[i]) {
					s.pop();
				}
				s.push(v[i]);
			}

		}
		for (auto i : leafs) {
			cout << i << ' ';
		}
		cout << v[n - 1];
		cout << endl;
	}
								 //code
	return 0;
}
