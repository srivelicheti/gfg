#include "stdafx.h"
#include <string>
#include <iostream>
#include <list>

using namespace ::std;

bool IsInterleaved(std::string s1, int p1, string s2, int p2, string s, int p)
{
	if (p >= s.length())
		return true;

	auto match1 = p1 < s1.length() && s1[p1] == s[p];
	auto match2 = p2 < s2.length() && s2[p2] == s[p];

	return  (match1 && IsInterleaved(s1, p1 + 1, s2, p2, s, p + 1)) || (match2 && IsInterleaved(s1, p1, s2, p2 + 1, s, p + 1));
}

bool IsInterleaved(string s1, string s2, string s)
{
	return  IsInterleaved(s1, 0, s2, 0, s, 0);
}