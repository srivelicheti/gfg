#include "stdafx.h"

namespace KPalindrome
{
	//Recursive func 
	//TODO: Convert this into memoization
	bool IsKPalin(string s, int i, int j, int k)
	{
		if (j <= i && k >= 0)
			return true;
		else if (k < 0)
			return false;

		if(s[i] == s[j])
		{
			return IsKPalin(s, i + 1, j - 1, k);
		}
		else
		{
			auto t1 = IsKPalin(s, i + 1, j, k - 1);
			auto t2 = t1 || IsKPalin(s, i, j - 1, k - 1);
			auto t3 = t2 || IsKPalin(s, i + 1, j - 1, k - 2);
			return  t3;
		}

	}

	/*You are required to complete this function*/
	bool is_k_palin(string s, int k)
	{
		int len = s.length();
		int** lookup = new int*[len];
		for (int i = 0; i < len; ++i)
		{
			lookup[i] = new int[len];
			for (int j = 0; j < len; ++j)
			{
				lookup[i][j] = -2;
				if (i == j)
					lookup[i][j] = 0;
			}
		}

		return IsKPalin(s, 0, len - 1, k);
		//Your code here
	}

	void KPalindrome_main()
	{
		cout << is_k_palin("acdcb", 2);
	}
}