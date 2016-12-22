#include "stdafx.h"
#include <unordered_set>


namespace YShapedListIntersection
{

	//Another method
	/* 
		* Method 3(Using difference of node counts)
		1) Get count of the nodes in first list, let count be c1.
		2) Get count of the nodes in second list, let count be c2.
		3) Get the difference of counts d = abs(c1 – c2)
		4) Now traverse the bigger list from the first node till d nodes so that from here onwards both the lists have equal no of nodes.
		5) Then we can traverse both the lists in parallel till we come across a common node. (Note that getting a common node is done by comparing the address of the nodes)
	 * 
	 */

	//Link list Node
	struct Node {
		int data;
		struct Node* next;
	};


	/* Should return data of intersection point of two linked
	lists head1 and head2.
	If there is no intersecting point, then return -1. */
	int intersectPoint(struct Node* head1, struct Node* head2)
	{
		std::unordered_set<Node*> set{};

		int res = -1;
		auto current = head1;
		while (current)
		{
			set.insert(current);
			current = current->next;
		}

		current = head2;
		while(current)
		{
			if(set.find(current) != set.end() )
			{
				res = current->data;
				break;
			}
			current = current->next;
		}
		return  res;
	}





	void YShapedListIntersection_main()
	{

	}
}
