#include  "stdafx.h"	

//http://www.practice.geeksforgeeks.org/problem-page.php?pid=700013



namespace ReverseListInGroups
{

	struct node
	{
		int data;
		struct node *next;
	};
	
	struct node *reverse(struct node *head, int k)
	{
		// Complete this method
		node* iHead = nullptr;
		node* iTail = nullptr;
		node* curr = head;
		node* prev = nullptr;
		node* temp = nullptr;
		node* revHead = nullptr;
		int i = 0;

		while(curr)
		{
			i++;
			temp = curr->next;
			if (i%k == 1)
			{ 
				iHead = curr;
				curr->next = nullptr;
			}
			else
				curr->next = prev;
			if(i%k == 0)
			{
				if (iTail)
					iTail->next = curr;

				iTail = iHead;
				prev = iHead;
				if (revHead == nullptr)
					revHead = curr;
			}
			else
			{
				prev = curr;
			}

			curr = temp;
		}
		if (i%k != 0)
			iTail->next = prev;
		if (revHead == nullptr)
			revHead = prev;
		return revHead;
	}

	

	void ReverseListInGroups_main()
	{
		
	}
}