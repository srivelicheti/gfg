// WordBreak.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <fstream>
#include <unordered_set>
#include <string>
using namespace std;
short Solve(int s, int e,int l ,short** mem, const string& w, const unordered_set<basic_string<char>>& dic)
{
	if(s<0||e<0 || s>e || s >=l || e>=l)
		return -1;

	if (mem[s][e] != -1) {
		//cout << "From cache :: " << s << " " << e << " " << mem[s][e];
		return mem[s][e];
	}

	if(s == e)
	{
		mem[s][e] = dic.find(string(1, (w[s]))) != dic.end() ? 1 : -1;
		return mem[s][e];
	}
	
	for(int i =e;i>=s;i-- )
	{
		auto lword = w.substr(i, e - i + 1);
		if(dic.find(lword) != dic.end())
		{
		//	mem[i] [l - 1] = 1;
			if((i == s) || Solve(s,i-1,l,mem,w,dic) == 1)
			{
				mem[s][e] = 1;
				return 1;
			}
		}
	}

	mem[s][e] = 0;
	return 0;
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

	while(t--)
	{
		int n;
		cin >> n;
		int i = 0;
		unordered_set<string> dic;
		while(i < n)
		{
			string s;
			cin >> s;
			dic.insert(s);
			i++;
		}

		string w;
		cin >> w;
		int l = w.length();
		auto mem = new short*[l];
		for(i=0;i<l;i++)
		{
			mem[i] = new short[l];
			for(int j=0;j<l;j++)
			{
				mem[i][j] = -1;
			}
		}
		Solve(0, l - 1, l ,mem, w, dic);
		cout << mem[0][l - 1] << endl;
	}

	return 0;
}
