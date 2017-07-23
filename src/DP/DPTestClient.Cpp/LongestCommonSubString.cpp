#include "stdafx.h"
#include <algorithm>

namespace LongestCommonSubString
{

	int LongestCommonSubString(string s, string t , int m, int n)
	{
		int** lookup = new int*[m+1];
		for (int i = 0; i < m+1; ++i)
		{
			lookup[i] = new int[n];
			for (int j = 0; j < n; ++j)
			{
				lookup[i][j] = 0;
			}
		}
		int maxLen = 0;
		for (int i = 1; i < m+1; ++i)
		{
			for (int j = 1; j < n+1; ++j)
			{
				if(s[i-1] == t[j-1])
				{
					lookup[i][j] = 1 + lookup[i - 1][j - 1];
					maxLen = std::max(lookup[i][j], maxLen);
				}
			}
		}

		return maxLen;
	}

	void LongestCommonSubString_main()
	{
		int T;
		cin >> T;
		for (int i = 0; i < T; ++i)
		{
			int m;
			cin >> m;
			int n;
			cin >> n;
			string s;
			cin >> s;
			string t;
			cin >> t;
			cout << LongestCommonSubString(s, t, m, n) << endl;
		}
	}
	int main()
	{

		//DistinctOccurancesAsSubSeq::DistinctOccurancesAsSubSeq_main();
		//MaxLengthChain::MaxLengthChain_main();
		//WildCardPatternMatching::WildCardPatternMatching_main();
		//KPalindrome::KPalindrome_main();
		LongestCommonSubString::LongestCommonSubString_main();
		return 0;
	}

}
