#include "stdafx.h"
#include <string>
#include <iostream>
#include <list>
#include <map>
using namespace  ::std;

std::map<std::string, int> _cache;

int GetCount(string s)
{
	if (s.length() == 0)
		return 0;
	if (s.length() == 1)
		return 1;

	if(_cache.find(s) != _cache.end())
	{
		
	}
}

int GetPalindromicSubSequenceCount(string s);


