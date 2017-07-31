// InfixToPostFixCPP.cpp : Defines the entry point for the console application.
//
// InfixToPostFixCpp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <fstream>
#include <unordered_map>
#include <stack>
#include <string>
using namespace std;

bool isOperand(char c) {
	return c == '+' || c == '-' || c == '/' || c == '*' || c == '^' || c == '(' || c == ')';
}

void Solve(unordered_map<char, int>& m, string s) {
	stack<string> op;
	stack<char> opr;

	for (int i = 0; i<s.length(); i++) {
		char c = s[i];
		if (isOperand(c)) {
			if (c == '(') {
				opr.push(c);
			}
			else if (c == ')') {
				while (!opr.empty() && opr.top() != '(') {
					auto lastOpr = opr.top(); opr.pop();
					auto op1 = op.top(); op.pop();
					auto op2 = op.top(); op.pop();
					op.push(op2 + op1 + lastOpr);
				}
				if (!opr.empty())
					opr.pop();
			}
			else {
				if (!opr.empty()) {
					int prior = m.find(c)->second;
					while (!opr.empty() && opr.top() != '(' && prior <= m.find(opr.top())->second) {
						auto lastOpr = opr.top(); opr.pop();
						auto op1 = op.top(); op.pop();
						auto op2 = op.top(); op.pop();
						op.push(op2 + op1 + lastOpr);
					}
				}
				opr.push(c);
			}
		}
		else {
			op.push(string(1, c));
		}

	}

	while (!opr.empty()) {
		auto lastOpr = opr.top(); opr.pop();
		auto op1 = op.top(); op.pop();
		auto op2 = op.top(); op.pop();
		op.push(op2 + op1 + lastOpr);
	}

	cout << op.top() << endl;


}

int main()
{
#if _DEBUG
	std::ifstream ins("input.txt");
	std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	std::cin.rdbuf(ins.rdbuf()); //redirect std::cin to in.txt!
#endif
	unordered_map<char, int> m;
	m.insert({ '-',1 });
	m.insert({ '+',1 });
	m.insert({ '*',2 });
	m.insert({ '/',2 });
	m.insert({ '^',3 });
	//m.insert({ '(',10 });

	int t;
	cin >> t;

	while (t--) {
		string s;
		cin >> s;
		Solve(m, s);
	}

	//code
	return 0;
}
