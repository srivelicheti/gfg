// QSortDLL.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

/* a Node of the doubly linked list */
struct Node
{
	int data;
	struct Node *next;
	struct Node *prev;
};

struct Node *lastNode(Node *root)
{
	while (root && root->next)
		root = root->next;
	return root;
}
void swap(int* a, int* b)
{
	int t = *a;      *a = *b;       *b = t;
}

Node* partition(Node *l, Node *h) {
	if (l == h)
		return l;
	if (l == nullptr)
		return h;
	if (h == nullptr)
		return l;

	Node* key = l;
	Node* part = l;

	Node* cur = l->next;
	auto end = h->next;
	while (cur != end) {
		auto next = cur->next;
		if (cur->data <key->data) {

			cur->prev->next = cur->next;
			if (cur->next)
				cur->next->prev = cur->prev;

			auto temp = part->next;
			part->next = cur;
			cur->prev = part;
			cur->next = temp;
			temp->prev = part;
			part = cur;
		}
		cur = next;
	}
	//l->prev = nullptr;
	if (key->next)
		key->next->prev = nullptr;
	auto temp = part->next;
	part->next = key;
	key->prev = part;
	key->next = temp;
	temp->prev = key;

	return key;


	//Your code goes here
}
void _quickSort(struct Node* l, struct Node *h)
{
	if (h != NULL && l != h && l != h->next)
	{
		struct Node *p = partition(l, h);
		_quickSort(l, p->prev);
		_quickSort(p->next, h);
	}
}

void quickSort(struct Node *head)
{
	// Find last Node
	struct Node *h = lastNode(head);

	// Call the recursive QuickSort
	_quickSort(head, h);
}
// A utility function to print contents of arr
void printList(struct Node *head)
{
	while (head)
	{
		cout << head->data << "  ";
		head = head->next;
	}
	cout << endl;
}
struct Node* newNode(int data) {
	struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data = data;
	temp->next = NULL;
	temp->prev = NULL;
	return temp;

}


/* Driver program to test above function */
int main()
{
#if _DEBUG
	std::ifstream ins("input.txt");
	std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	std::cin.rdbuf(ins.rdbuf()); //redirect std::cin to in.txt!
#endif
	int t, x, n, i;
	cin >> t;
	while (t--)
	{
		/* Start with the empty list */
		struct Node *p, *temp, *head = NULL;
		cin >> n >> x;
		head = newNode(x);
		p = head;
		for (i = 0; i<n - 1; i++) {
			cin >> x;
			/* Let us create the doubly linked list 10<->8<->4<->2 */
			temp = newNode(x);
			p->next = temp;
			temp->prev = p;
			p = p->next;
		}
		//printList(head); 
		/* delete Nodes from the doubly linked list */

		quickSort(head);
		/* Modified linked list will be NULL<-8->NULL */
		printList(head);
		while (head->next != NULL)
		{
			temp = head;
			head = head->next;
			free(temp);
		}
		free(head);
	}
	return 0;
}
