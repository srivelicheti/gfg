#include "stdafx.h"
#include <string>
#include <iostream>
#include <list>
#include <map>
using namespace  ::std;

//std::map<std::string, int> _cache;
int cacheCount = 0;
long GetCount(string s, std::map<std::string, int>* cache)
{
	if (s.length() == 0 || s == "")
		return 0;
	if (s.length() == 1)
	{
		cacheCount++;
		return 1;
	}
	auto cacheIitem = cache->find(s);
	if(cacheIitem != cache->end())
	{
		cacheCount++;
		return  cacheIitem->second;
	}
	auto suffixIndex = s.length() - 1;
	auto prefixString = s.substr(0, suffixIndex);
	auto suffixChar = s[suffixIndex];
	auto prefixPalindromeCount = GetCount(prefixString,cache);
	long count = 1;
	for(int i=0;i<s.length() -2 ;i++)
	{
		if(s[i] == suffixChar)
		{
			auto innerPalindromeCount = 
				GetCount(s.substr(i + 1, suffixIndex - (i + 1)),cache);
			count = innerPalindromeCount + 1 + count;
		}
	}
	auto totalCount = prefixPalindromeCount + count;
	cache->insert_or_assign(s, totalCount);
	return totalCount;


}

long GetPalindromicSubSequenceCount(string s)
{
	cacheCount = 0;
	
	std::map<std::string, int>* cache = new std::map<std::string, int>() ;
	auto totalCount = GetCount(s, cache);
	cout << "Got from cache " << cacheCount << std::endl;
	return  totalCount;
}


