#include "stdafx.h"
#include <vector>
#include <stack>

using namespace std;
namespace TreeTraversal
{
	
	struct Node
	{
		int data;
		Node* left;
		Node* right;
	};

	std::vector<Node*> InOrderTraversal(Node* root)
	{
		Node* current = root;
		std::stack<Node*> s;
		vector<Node*> v;
		while(!s.empty() || current)
		{
			if(current)
			{
				s.push(current);
				current = current->left;
			}
			else
			{
				auto t = s.top() ;
				s.pop();
				v.push_back(t);
				current = t->right;
			}
		}
	}


	void InorderTraversal_main()
	{
		

	}
}
