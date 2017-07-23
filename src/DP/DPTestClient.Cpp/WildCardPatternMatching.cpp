#include "stdafx.h"
#include <algorithm>
#include <iterator>


namespace WildCardPatternMatching
{
	//TODO: can implement a bottom up solution with cache.

	/*You are required to complete this method*/
	int** cache;
	bool wildCard_internal(string pattern, string str, int i, int j)
	{
		if (j < 0)
		{
			return false;
		}
		else if (i < 0  )
		{
			bool allRemAre = true;
			auto remCharIndex = j;
			while (remCharIndex >= 0)
			{
				if (pattern[remCharIndex] != '*')
				{
					allRemAre = false;
					break;
				}
				remCharIndex--;
			}
			return allRemAre;
		}
		auto patChar = pattern[j];
		auto currChar = str[i];
		if (i == 0)
		{
			if (j == 0 && (str[i] == patChar || patChar == '*' || patChar == '?'))
				return true;
		}

		if (patChar == '*')
		{
			while (j > 0 && pattern[j - 1] == '*')
			{
				j = j - 1;
			}
			auto wildCharRem1 = wildCard_internal(pattern, str, i, j - 1); //Match * with empty char
			auto wildCharRem = wildCard_internal(pattern, str, i - 1, j); //Match * with last char and still include * in the next sub string
			auto wildCarConsum = wildCard_internal(pattern, str, i - 1, j - 1); //Match * with one char and remove * from next search
			return wildCharRem1 || wildCarConsum || wildCharRem;
		}
		else if (patChar == '?')
		{
			return wildCard_internal(pattern, str, i - 1, j - 1);
		}
		else
			return patChar == str[i] && wildCard_internal(pattern, str, i - 1, j - 1);
	}

	/*You are required to complete this method*/
	int wildCard(string pattern, string str)
	{
		

		int i = str.length() - 1;
		int j = pattern.length() - 1;
		if (wildCard_internal(pattern, str, i, j))
			return 1;
		else
			return 0;
	}

	void WildCardPatternMatching_main()
	{
		/*Text = "baaabab",
Pattern = “*****ba*****ab", output : true
Pattern = "baaa?ab", output : true
Pattern = "ba*a?", output : true
Pattern = "a*ab", output : false */
		cout << wildCard("?a*ab","adab" ) << endl;
	}
}
