#include "stdafx.h"
#include "stdio.h"
//http://www.practice.geeksforgeeks.org/problem-page.php?pid=700192

namespace FlattenAndSortLinkedList {

	//node structure  used in the program
	struct node {
		int data;
		struct node * next;
		struct node * bottom;
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
			n1 = n1->bottom;
		}
		else
		{
			resHead = n2;
			n2 = n2->bottom;
		}
		node* prev = resHead;
		while (n1 && n2)
		{
			if (n1->data < n2->data)
			{
				prev->bottom = n1;
				n1 = n1->bottom;
				prev = prev->bottom;
			}
			else
			{
				prev->bottom = n2;
				n2 = n2->bottom;
				prev = prev->bottom;
			}
		}
		if (n1)
			prev->bottom = n1;
		else if (n2)
			prev->bottom = n2;


		return 	resHead;
	}

	/* arr[] is an array of pointers to heads of linked lists
	and N is size of arr[]  */
	node * mergeKList(node *arr[], int N)
	{
		int last = N - 1;
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


	/*  Function which returns the  root of
	the flattened linked list. */
	node *flatten(node *root)
	{

		if (root == nullptr)
			return root;


		auto current = root;

		node* arr[50]{ nullptr };
		int i = 0;
		while (current)
		{
			auto next = current->next;
			arr[i] = current;
			current->next = nullptr;
			current = next;
			i++;
		}
		auto merged = mergeKList(arr, i);
		return merged;
	}


	void printList(node *node)
	{
		while (node != NULL)
		{
			printf("%d ", node->data);
			node = node->bottom;
		}
	}


	void FlattenAndSort_main() {

		int t;
		cin >> t;
		while (t--) {
			int n, m, flag = 1, flag1 = 1;
			struct node * temp = NULL;
			struct node * head = NULL;
			struct node * pre = NULL;
			struct node * tempB = NULL;
			struct node * preB = NULL;
			cin >> n;
			int* work = new int[n];
			for (int i = 0; i < n; i++)
				cin >> work[i];
			for (int i = 0; i < n; i++) {
				m = work[i];
				--m;
				temp = (struct node*)malloc(sizeof(struct node));

				cin >> temp->data;
				//scanf("%d", &temp->data);
				temp->next = NULL;
				temp->bottom = NULL;
				if (flag) {
					head = temp;
					pre = temp;
					flag = 0;
					flag1 = 1;
				}
				else {
					pre->next = temp;
					pre = temp;
					flag1 = 1;
				}
				for (int j = 0; j < m; j++) {
					tempB = (struct node*)malloc(sizeof(struct node));
					cin >> tempB->data;
					//scanf("%d", &tempB->data);
					tempB->next = tempB->bottom = NULL;
					if (flag1) {
						temp->bottom = tempB;
						preB = tempB;
						flag1 = 0;
					}
					else {
						preB->bottom = tempB;
						preB = tempB;
					}
				}
			}
			node *fun = head;
			node *fun2 = head;
			/*
			while(fun!=NULL)
			{

			cout<<fun->data<<" ";
			fun2 = fun->bottom;
			fun=fun->next;

			while(fun2){
			cout<<fun2->data<<" ";
			fun2=fun2->bottom;
			}
			cout<<endl;
			}*/

			node* root = flatten(head);
			printList(root);
			cout << endl;

		}
		//return 0;
	}
}
