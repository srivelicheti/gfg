#include "stdafx.h"
#include <string>
#include <algorithm>
#include <iostream>


namespace DistinctOccurancesAsSubSeq
{

	/*char GetCharAt(std::string s, int i) {

	}*/

	/*You are required to complete this method*/
	int subsequenceCount(std::string S, std::string T)
	{
		//Your code here
		int slen = S.size();
		int tlen = T.size();

		auto arr = new int*[tlen + 1]; // [slen];
		for (int i = 0; i < tlen + 1; ++i)
		{
			arr[i] = new int[slen + 1];
			arr[i][0] = 0;
			if (i == 0)
			{
				for (int j = 0; j < slen + 1; ++j)
				{
					arr[0][j] = 0;
				}
			}
		}
		int c = 0;
		for (int i = 1; i < tlen + 1; ++i)
		{
			for (int j = 1; j < slen + 1; ++j)
			{
				if (T[i - 1] == S[j - 1])
				{
					arr[i][j] = 1 + arr[i - 1][j - 1];
					if(i == tlen)
					{
						if (arr[i][j] == tlen)
							c++;
					}
				}
				else
					arr[i][j] = std::max(arr[i - 1][j], arr[i][j - 1]);
			}
		}
		
		return c;
	}



	void DistinctOccurancesAsSubSeq_main() {
		std::cout << subsequenceCount("banana", "ban");
	}
}
