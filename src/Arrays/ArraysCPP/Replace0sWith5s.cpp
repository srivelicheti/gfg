#include "stdafx.h"
#include <iostream>

using namespace std;

int Replace0sWith5s(int n)
{
	int input = n;
	int multiplier = 1;
	int modulo = 10;
	int toAdd = 0;
	while(true)
	{
		if (input % modulo == 0)
			toAdd = toAdd + (multiplier * 5);

		multiplier = multiplier * 10;
		if(input < 10)
			break;

		input = input / 10;

	}

	return n + toAdd;
}