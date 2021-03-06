// GenerateIPAddresses.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>
#include <tuple>
#include <algorithm>
#include <string>
using namespace std;

using namespace std;

bool ______________ok(int a, int b, int c, int d)
{
	return a <= 255 and b <= 255 and c <= 255 and d <= 255;
}

string ____________G(int a, int b, int c, int d)
{
	return to_string(a) + "." + to_string(b) + "." + to_string(c) + "." + to_string(d);
}


vector<string> _______________ip(string s)
{
	vector<string> res;
	for (int i = 1; i <= 3; i++)
	{
		for (int j = 1; j <= 3; j++)
		{
			for (int k = 1; k <= 3; k++)
			{
				for (int l = 1; l <= 3; l++)
				{
					if (i + j + k + l == s.length())
					{
						int a = stoi(s.substr(0, i));
						int b = stoi(s.substr(i, j));
						int c = stoi(s.substr(i + j, k));
						int d = stoi(s.substr(i + j + k, l));

						if (______________ok(a, b, c, d))
						{
							string str = ____________G(a, b, c, d);
							/*+3 because of 3 dots*/
							if (str.length() == s.length() + 3)
							{
								res.push_back(str);
							}
						}
					}
				}
			}
		}
	}
	return res;
}


void GenerateIp(string s, int remDots, string prefix, vector<string>& addresses  ) {
	
	auto len = s.length();
	if (len == 0)
		return;

	if (remDots == 0) { 
		if(len == 1)
			addresses.push_back(prefix + s);
		else if(len <= 3 && s[0] != '0' && stoi(s) <= 255)
			addresses.push_back(prefix + s);
		return; 
	}
	if (remDots >= len || len > ((remDots +1) * 3)) return;

	//place dot after first second and third characters and recurse
	auto newPrefix = prefix + s[0] + ".";
	GenerateIp(s.substr(1), remDots - 1, newPrefix, addresses);

	if (s.length() >= 2 && s[0] != '0') {
		newPrefix = prefix + s.substr(0,2) + "." ;
		GenerateIp(s.substr(2), remDots - 1, newPrefix, addresses);
	}

	if (s.length() >= 3 && s[0] != '0') {
		newPrefix = prefix + s.substr(0, 3) + "." ;
		if (stoi(s.substr(0, 3)) <= 255) {
			GenerateIp(s.substr(3), remDots - 1, newPrefix , addresses);
		}
	}
	return;

}


vector<string> genIp(string s) {
	vector<string> addresses;
	GenerateIp(s, 3, "", addresses);

	return addresses;
}
int main()
{
#if _DEBUG
	std::ifstream ins("in.txt");
	std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	std::cin.rdbuf(ins.rdbuf()); //redirect std::cin to in.txt!
#endif
	int T;
	cin >> T;
	while (T--)
	{
		string s;
		cin >> s;

		/*generating naively*/
		vector<string> str = _______________ip(s);
		sort(str.begin(), str.end());
		vector<string> res = genIp(s);
		sort(res.begin(), res.end());

		if (res.size() != str.size())
			cout << 0 << endl;
		else {
			bool f = true;
			for (int i = 0; i<str.size(); i++)
			{
				if (res[i] != str[i])
				{
					f = false;
					cout << 0 << endl;
					break;
				}
			}
			if (f)
				cout << 1 << endl;
		}
	}
}


