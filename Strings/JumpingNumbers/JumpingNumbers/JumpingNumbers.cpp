// JumpingNumbers.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


#include <iostream>
#include <fstream>
#include <stack>
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
	while (t--) {
		int n;
		cin >> n;
		cout << 0 << " ";
		stack<int> s;
		if (n >= 9)
			s.push(9);
		if (n >= 8)
			s.push(8);
		if (n >= 7)
			s.push(7);
		if (n >= 6)
			s.push(6);
		if (n >= 5)
			s.push(5);
		if (n >= 4)
			s.push(4);
		if (n >= 3)
			s.push(3);
		if (n >= 2)
			s.push(2);
		if (n >= 1)
			s.push(1);

		while (!s.empty()) {
			int top = s.top();
			s.pop();
			cout << top << " ";
			int ld = top % 10;
			int bld = ld - 1;
			int nld = ld + 1;
			
			if (nld <=9) {
				int next = (top * 10) + nld;
				if(next <= n)
					s.push(((top * 10) + nld));
			}
			if (bld >= 0) {
				int next = (top * 10) + bld;
				if(next <=n)
					s.push(((top * 10) + bld));
			}

		}
		cout << endl;

	}

	//code
	return 0;
}
