// CppStrings.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <list>


using namespace ::std;

bool IsInterleaved(string s1, string s2, string s);
void PrintIfAdditive(string num);
bool IsValidAddress(char* s);
long GetPalindromicSubSequenceCount(string s);

int main()
{
	int i = 1;
	do
	{
		string s;
		cout << "Enter String " << endl;
		cin >> s;
		cout << GetPalindromicSubSequenceCount(s);

		cin >> i;
	} while (i == 1);
	
}

