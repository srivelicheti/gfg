#include "stdafx.h"

struct Node
{
	int data;
	struct Node* next;
};


Node * deleteK(Node *head, int K)
{
	if (K == 0)
		return head;
	else if (K == 1)
		return nullptr;

	int toDelete = K;
	Node* prev = nullptr;
	Node* current = head;
	int i = 0;
	while(current)
	{
		++i;
		if (i == toDelete)
		{
			prev->next = current->next;
			toDelete += K;
		}
		else
			prev = current;
		current = current->next;
	}
	return head;
	//Your code here
}