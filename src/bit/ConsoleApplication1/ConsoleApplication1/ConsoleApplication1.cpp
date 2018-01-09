// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <algorithm>
#include <string>

#include <iostream>
#include <fstream>
using namespace std;

int convertToInt(string s) {
	int total = 0;
	int n = s.length();
	for (int i = 0; i<n; i++) {
		int c = (s[n - i - 1] - '0');
		total += c * pow(2, i);
	}

	return total;
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
		string s;
		cin >> s;
		int n = s.length();
		int i = n - 1;
		int rem = 0;
		
		while (i>=0) {
			int j = 0;
			string curS = i - 3 < 0 ? s.substr(0,  i+1) : s.substr(i - 3, 4);
			i -= 4;
			rem = (convertToInt(curS) + rem) % 3;

		}
		if (rem == 0)
			cout << "1" << endl;
		else
			cout << "0" << endl;
	}
	//code
	return 0;
}
