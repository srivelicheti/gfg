#include "stdafx.h"
#include <ostream>
#include <iostream>

namespace MaxLengthChain
{
	//Not Completed
	//http://www.practice.geeksforgeeks.org/problem-page.php?pid=700342

	//The paris can be arranged in any order not just in the order that they are given.

	struct val {
		int first;
		int second;
	};

	/*You are required to complete this method*/
	int maxChainLen(val p[], int n)
	{
		int* count = new int[n] {1};
		//int* max = new int[n] {-1};
		//max[0] = p[0].second;
		int runMax = p[0].second;
		int maxCount = 1;
		

		for (int i = 1; i < n; i++)
		{
			auto curr = p[i];
			if(curr.first > runMax)
			{
				runMax = curr.second;
				maxCount++;
				count[i] = maxCount;
			}
			else
			{
				int selectedCount = 1;
				for (int j = i-1; j >= 0; --j)
				{
					if (curr.first > p[j].second)
					{
						if (count[j] + 1 > selectedCount)
							selectedCount = count[j] + 1;
					}
				}
				count[i] = selectedCount;
				if(selectedCount > maxCount)
				{
					maxCount = selectedCount;
					runMax = curr.second;
				}
				else if(selectedCount == maxCount && curr.second < runMax)
				{
					runMax = curr.second;
				}
			}
		}

		return maxCount;
	}

	void MaxLengthChain_main() {
		// your code goes here
		int t;
		std::cin >> t;
		while (t--)
		{
			int n;
			std::cin >> n;
			auto p = new val[n];
			for (int i = 0; i<n; i++)
			{
				std::cin >> p[i].first >> p[i].second;
			}

			std::cout << maxChainLen(p, n) << std::endl;
		}
		
	}

}
