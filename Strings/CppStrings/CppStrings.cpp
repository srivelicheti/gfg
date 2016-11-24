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

int main()
{
	int i = 1;
	do
	{
		cout << "Enter ip add" << std::endl;
		std::string temp;
		cin >> temp;
		char* s = &temp[0];// "192..11.24.111";

		bool isValid = IsValidAddress(s);

		cout << isValid;

		cin >> i;
	} while (i == 1);
	
}

