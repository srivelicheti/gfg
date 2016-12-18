// Tries.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
using namespace std;

class TrieNode
{

private:
	const int lowerBound = static_cast<int>('a');
	int ToIndex(char c) const
	{
		return 	static_cast<int>(c) - lowerBound;
	}

	TrieNode* InsertNextChar(char c)
	{
		int index = ToIndex(c);
		auto next = Next[index];
		if (!next)
		{
			Next[index] = new TrieNode(c);
		}
		return Next[index];
	}
public:
	TrieNode* Next[26]{};
	char CurrentChar;
	bool IsValue;
	TrieNode(char c)
	{

		CurrentChar = c;
		IsValue = false;

	}

	TrieNode(string s)
	{

		CurrentChar = s[0];
		IsValue = false;

		if (s.length() == 1)
		{
			IsValue = true;
		}
		else
		{
			InsertString(s, 1, s.length());
		}
	}

	TrieNode* InsertString(string s, int startIndex, int stringLength)
	{
		auto currentNode = this;
		for (int i = startIndex; i < stringLength; ++i)
		{
			currentNode = currentNode->InsertNextChar(s[i]);
		}

		currentNode->IsValue = true;

		return currentNode;
	}

	int TotalCount()
	{
		int count(0);

		for (auto node : Next)
		{
			if (node)
				count = count + node->TotalCount();
		}

		if (IsValue)
			++count;

		return  count;

	}

	int TotalPrefixStringCount()
	{
		int count(0);

		for (auto node : Next)
		{
			if (node)
				count = count + node->TotalPrefixStringCount();
		}

		++count;

		return  count;
	}


};

class SuffixTrie
{
private:
	TrieNode* _root[26]{};
	const int radix = 26;

	static int ToIndex(char c)
	{
		return 	static_cast<int>(c) - static_cast<int>('a');
	}

	void Insert(string s, int startIndex, int stringLength)
	{
		if (startIndex >= s.length() || s.length() == 0)
			return;

		auto fistChar = s[startIndex];
		auto index = ToIndex(fistChar);

		auto nextNode = _root[index];
		if (nextNode)
		{
			nextNode->InsertString(s, startIndex + 1, stringLength);
		}
		else
		{
			_root[index] = new TrieNode(fistChar);
			_root[index]->InsertString(s, startIndex + 1, stringLength);
		}
	}

public:
	SuffixTrie()
	{

	}

	void InsertSuffixString(string s)
	{
		int stringLength = s.length();
		for (auto i = 0; i < stringLength; ++i)
		{
			Insert(s, i, stringLength);
		}
	}

	int Count()
	{
		auto count = 0;
		for (auto node : _root)
		{
			if (node)
				count += node->TotalPrefixStringCount();
		}
		count++;//for empty string
		return  count;
	}

};

int countDistinctSubstring(string s)
{
	SuffixTrie trie{};
	trie.InsertSuffixString(s);
	return trie.Count();
	//Your code here
}

int main()
{
	//SuffixTrie trie;
	cout << "Enter a string" << endl;
	string input;

	getline(cin, input);

	while (input != "exit")
	{
		try
		{
			cout << "Total Substrings count: " << countDistinctSubstring(input) << endl;
		}
		catch (const exception& ex)
		{
			cout << ex.what() << endl;
		}



		//cout << "Total Substrings count: " << trie.Count() << endl;

		cout << "Enter a string" << endl;
		getline(cin, input);
	}
	return 0;
}

