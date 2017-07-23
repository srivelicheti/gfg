// SegEvenOddCPP.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


#include <iostream>
#include <fstream>

using namespace std;

struct node {
	int data;
	node* next;
};

node* SegEvenOd(node* head) {
	node* lastOdd = nullptr;
	node* firstEven = nullptr;
	node* lastEven = nullptr;
	node* firstOdd = nullptr;
	auto cur = head;
	int i = 0;
	while (cur != nullptr) {
		auto next = cur->next;
		cur->next = nullptr;
		if (cur->data % 2 == 1) {
			if (firstOdd == nullptr) {
				firstOdd = cur;
				if (lastEven) {
					lastEven->next = firstOdd;
				}
			}
			else {
				lastOdd->next = cur;

			}
			lastOdd = cur;
		}
		else {
			if (lastEven != nullptr) {
				lastEven->next = cur;
			}
			lastEven = cur;
			if (firstEven == nullptr)
				firstEven = lastEven;
			cur->next = firstOdd;
		}
		cur = next;
	}

	if (!firstEven)
		return firstOdd;
	else
		return firstEven;
}

void SolveOne() {
	int n;
	cin >> n;
	int data;
	cin >> data;
	node* prev = new node{ data,nullptr };
	node* head = prev;
	n--;
	while (n--) {
		cin >> data;
		prev->next = new node{ data,nullptr };
		prev = prev->next;
	}

	auto ret = SegEvenOd(head);
	// auto ret = head;
	while (ret != nullptr)
	{
		//cout << ret->data <<" ";
		ret = ret->next;
	}
	cout << endl;
}

int main()
{
#if _DEBUG
	std::ifstream ins("input.txt");
	std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	std::cin.rdbuf(ins.rdbuf()); //redirect std::cin to in.txt!
#endif
	int t;
	cin >> t;
	while (t--) {
		SolveOne();
	}
	//code
	return 0;
}
