#include "stdafx.h"
#include <string>
#include <iostream>

bool IsValidAddress(char* s)
{
	bool isValid(true);
	int noOfParts = 0;
	
	std::string currentNum;
	bool addOne = false;
	for(char *it = s; *it; ++it)
	{
		//std::cout << *it;
		if(*it == '.')
		{
			noOfParts++;
			addOne = false;
			if(noOfParts >= 5)
			{
				isValid = false;
				break;
			}
			currentNum = "";
			continue;
		}
		currentNum = currentNum + *it;

		try
		{
			addOne = true;
			std::string::size_type sz;
			int n = std::stoi(currentNum, &sz);
			if(n>255)
			{
				isValid = false;
				break;
			}
		}
		catch (...)
		{
			isValid = false;
			break;
		}

		
	}
	if (addOne)
		noOfParts++;

	return isValid && noOfParts == 4;

}