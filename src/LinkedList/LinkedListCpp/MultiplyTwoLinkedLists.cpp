#include "stdafx.h"
#include <iostream>
#include <tuple>
//http://www.practice.geeksforgeeks.org/problem-page.php?pid=700336

namespace ReverseLinkedList
{
	struct node
	{
		int data;
		struct node* next;
	};

	pair<node*, int> reverse_linkedlist(node* n)
	{
		if (n)
		{
			auto current = n;
			node* prev = nullptr;
			node* next = nullptr;// n->next;
			int i = 1;
			while (current)
			{
				i++;
				next = current->next;
				current->next = prev;
				prev = current;
				current = next;
			}

			return{ prev,i };
		}

		return{ n,0 };
	}

	long long GetLinkedListAsNumber(node* n, long long mod)
	{
		auto current = n;
		long long n1 = 0;
		long long i = 1;
		while (current)
		{
			n1 += ((current->data * i) % mod);
			n1 = n1%mod;
			i = (i * 10) % mod;
			current = current->next;
		}

		return n1;
	}

	/*You are required to complete this method*/
	long long  multiplyTwoLists(node* l1, node* l2)
	{
		//Your code here
		auto reversed1 = reverse_linkedlist(l1);
		auto reversed2 = reverse_linkedlist(l2);

		auto rl1 = reversed1.first;
		auto rl2 = reversed2.first;

		long long mod = static_cast<long long>(pow(10, 9) + 7);

		long long n1 = GetLinkedListAsNumber(rl1, mod);
		long long n2 = GetLinkedListAsNumber(rl2, mod);

		return  ((n1%mod) * (n2%mod)) % mod;

	}

	struct node *newNode(int data)
	{
		struct node *new_node = (struct node *) malloc(sizeof(struct node));
		new_node->data = data;
		new_node->next = NULL;
		return new_node;
	}


	void reverse(node **r)
	{
		node *prev = NULL;
		node *cur = *r;
		node *nxt;
		while (cur != NULL)
		{
			nxt = cur->next;
			cur->next = prev;
			prev = cur;
			cur = nxt;
		}
		*r = prev;
	}
	/* Function to insert a node at the beginning of the Doubly Linked List */
	void push(struct node** head_ref, int new_data)
	{
		/* allocate node */
		struct node* new_node = newNode(new_data);

		/* link the old list off the new node */
		new_node->next = (*head_ref);

		/* move the head to point to the new node */
		(*head_ref) = new_node;
	}


	void freeList(struct node *node)
	{
		struct node* temp;
		while (node != NULL)
		{

			temp = node;
			node = node->next;
			free(temp);
		}

	}




	/* Driver program to test above function */
	void multipytwolinkedlist_main()
	{


		int t, n, m, i, x;
		cin >> t;
		while (t--)
		{

			struct node* first = NULL;
			struct node* second = NULL;
			cin >> n;
			for (i = 0; i < n; i++)
			{
				cin >> x;
				push(&first, x);
			}
			cin >> m;
			for (i = 0; i < m; i++)
			{
				cin >> x;
				push(&second, x);
			}

			reverse(&first);
			reverse(&second);
			long long res = multiplyTwoLists(first, second);
			cout << res << endl;
			freeList(first);
			freeList(second);

		}
		//return 0;
	}
}







