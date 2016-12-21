#include "stdafx.h"
#include <stack>

namespace DeleteNodesHaingGreaterOnRight
{

	struct Node
	{
		int data;
		Node* next;
	};



	Node *compute_old(Node *head)
	{
		stack<Node*> st{};

		auto current = head;

		while(current)
		{
			if(st.size() == 0 || st.top()->data >= current->data )
			{
				st.push(current);
			}
			else
			{
				while(st.size() > 0 && st.top()->data< current->data)
				{
					st.pop();
				}
				st.push(current);
			}

			current = current->next;
		}
		Node* prev = nullptr;
		while(st.size() > 0)
		{
			auto next = st.top();
			next->next = prev;
			prev = next;
			st.pop();
		}
		return prev;
		// your code goes here
	}

	Node* reverse(Node* n)
	{
		auto current = n;
		Node* temp = nullptr;
		Node* prev = nullptr;

		while (current)
		{
			temp = current->next;
			current->next = prev;
			prev = current;
			current = temp;
		}

		return prev;
	}


	Node *compute(Node *head)
	{
		// current = head;
		if (head == nullptr)
			return nullptr;

		auto rlist = reverse(head);
		auto resHead = rlist;
		auto current = rlist;
		
		while(current && current->next)
		{
			if(current->next->data < current->data)
				current->next = current->next->next;
			else
				current = current->next;
		}

		return reverse(resHead);

		// your code goes here
	}

	
	void DeleteNodesHaingGreaterOnRight_main()
	{

	}
}