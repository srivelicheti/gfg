#include "stdafx.h"
#include "NStackBooks.h"


NStackBooks::NStackBooks()
{
}


NStackBooks::~NStackBooks()
{
}

int NStackBooks::GetMaxBooks(int a[], int n, int k)
{
	//int (*cache)[variable-declarator n, type: int, initializer:] = new int[n][n];
	int** cache = new int*[n];
	for (int i = 0; i < n; i++)
	{
		cache[i] = new int[n];
	}
	//memset(cache, 0, sizeof(cache[0][0]) * n * n);

	int maxCollected = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (i == j)
			{
				cache[i][j] = a[i] <= k ? a[i] : -1;
				maxCollected = maxCollected < cache[i][i] ? cache[i][i] : maxCollected;
			}
			else if (cache[j][i - 1] == -1)
			{
				cache[j][i] = -1;
			}
			else
			{
				auto preConsec = cache[j][i-1];
				if ((a[i]) <= k)
				{
					cache[j][i] = preConsec + a[i];
					if (maxCollected <= cache[j][i])
						maxCollected = cache[j][i];
				}
				else
					cache[j][i] = -1;
			}
		}
	}
	return maxCollected;
}
