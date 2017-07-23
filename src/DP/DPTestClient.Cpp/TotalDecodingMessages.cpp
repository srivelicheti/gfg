#include "stdafx.h"
#include <sstream>
//http://www.practice.geeksforgeeks.org/problem-page.php?pid=1234

namespace TotalDecodingMessages
{
	int TotalDecodingMessages(std::string s , int l)
	{
		int* a = new int[l]{0};
		if (s[0] != '0')
			a[0] = 1;

		for (int i = 1; i < l; ++i)
		{
			if (s[i] != '0')
				a[i] += a[i - 1];

			if (s[i - 1] != '0') {
				string lastTwoChar = s.substr(i - 1, 2);
				if (stoi(lastTwoChar) <= 26)
				{
					if (i == 1)
						a[i]++;
					else
						a[i] += a[i - 2];
				}
			}
		}

		return a[l - 1];

	}

	void TotalDecodingMessages_main()
	{
		/*string s = "124";
		auto t = s.substr(1, 2);
		cin >> s;
		t = s.substr(1, 2);*/
		int n;
		cin >> n;
		while(n--)
		{
			int l;
			cin >> l;
			std::string s;
			cin >> s;
//			s = s.substr(2, l - 2);
			cout << TotalDecodingMessages(s, l) << endl;

		}
	}
}