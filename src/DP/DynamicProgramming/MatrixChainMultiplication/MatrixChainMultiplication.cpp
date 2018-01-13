// MatrixChainMultiplication.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <unordered_map>
#include <tuple>
#include <algorithm>
using namespace std;
using ll = long long;


struct pair_hash {
	template <typename T1, typename T2>
	std::size_t operator () (const std::pair<T1, T2> &p) const {
		auto h1 = std::hash<T1>{}(p.first);
		auto h2 = std::hash<T2>{}(p.second);

		// Mainly for demonstration purposes, i.e. works but is overly simple
		// In the real world, use sth. like boost.hash_combine
		return h1 ^ h2;
	}
};

using umap_pi = unordered_map<pair<int, int>, ll, pair_hash>;

ll Solve(int* arr, int i, int j, int&n ,umap_pi& map) {
	if (j == i + 1)
		return 0;

	auto cached = map.find({ i,j });
	if (cached != map.end()) return cached->second;

	if (j - i == 2) {
		ll f{ arr[i] }; ll s{ arr[i + 1] }; ll t{ arr[j] };
		ll res = f * s * t;
		map.insert({ {i,j},res });
		return res;
	}

	//first matrix as stand alone
	auto res = Solve(arr, i+1, j, n, map);
	ll f{ arr[i] }; ll s{ arr[i + 1] }; ll t{ arr[j] };
	auto tres = f * s * t;
	res += tres;

	//first and second as one
	auto fsres1 = Solve(arr, i, i + 2,n,map);
	auto fsres2 = Solve(arr, i + 2, j, n, map);
	f = { i }; s = { i + 2 }; t = { j };
	auto fres = fsres1 + fsres2 + (f*s*t);

	auto finalres = min(res, fres);

	map.insert({ {i,j},finalres });
	return finalres;
}

int main()
{
#if _DEBUG
	std::ifstream ins("in.txt");
	std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	std::cin.rdbuf(ins.rdbuf()); //redirect std::cin to in.txt!
#endif

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		auto arr = new int[n];
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
		}
		umap_pi map;
		cout << Solve(arr, 0, n - 1, n, map) << endl;

	}
								 //code
	return 0;
}