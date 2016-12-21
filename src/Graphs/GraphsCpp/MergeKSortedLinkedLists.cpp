#include "stdafx.h"

//http://www.practice.geeksforgeeks.org/problem-page.php?pid=700265

struct node
{
	int data;
	struct node* next;
};

node* mergetwolinkedlists(node* n1, node* n2)
{
	if (n1 == nullptr && n2 == nullptr)
		return nullptr;
	else if (n1 == nullptr && n2)
		return n2;
	else if (n2 == nullptr && n1)
		return n1;

	node* resHead = nullptr;
	if (n1->data < n2->data)
	{
		resHead = n1;
		n1 = n1->next;
	}
	else
	{
		resHead = n2;
		n2 = n2->next;
	}
	node* prev = resHead;
	while (n1 && n2)
	{
		if (n1->data < n2->data)
		{
			prev->next = n1;
			n1 = n1->next;
			prev = prev->next;
		}
		else
		{
			prev->next = n2;
			n2 = n2->next;
			prev = prev->next;
		}
	}
	if (n1)
		prev->next = n1;
	else if (n2)
		prev->next = n2;


	return 	resHead;
}

/* arr[] is an array of pointers to heads of linked lists
and N is size of arr[]  */
node * mergeKList(node *arr[], int N)
{
	int last = N;
	while (last != 0)
	{
		int i = 0, j = last;

		// (i, j) forms a pair
		while (i < j)
		{
			// merge List i with List j and store
			// merged list in List i
			arr[i] = mergetwolinkedlists(arr[i], arr[j]);

			// consider next pair
			i++, j--;

			// If all pairs are merged, update last
			if (i >= j)
				last = j;
		}
	}

	return arr[0];
	// Your code here
}

/* arr[] is an array of pointers to heads of linked lists
and N is size of arr[]  */
node * mergeKListOld(node *arr[], int N)
{
	if (N == 0)
		return  nullptr;
	else if (N == 1)
		return arr[0];
	/*else if (N == 2)
		return  mergetwolinkedlists(arr[0], arr[1]);*/

	auto merged = arr[0];

	for (int i = 0; i < N; )
	{
		merged = mergetwolinkedlists(merged, arr[i]);
		i = i + 2;
	}

	return merged;
	// Your code here
}

