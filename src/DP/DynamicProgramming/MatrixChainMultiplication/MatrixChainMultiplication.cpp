// MatrixChainMultiplication.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <unordered_map>
#include <tuple>
#include <algorithm>
#include <string>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

//Wrong code, never completed it

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

using umap_pi = unordered_map<string, ll>;

ll Solve(pii* arr, int i, int j, int k, umap_pi& map) {
	if (i == k) return 0;

	auto key = to_string(i) + '_' + to_string(k);

	auto cached = map.find(key);
	if (cached != map.end()) {
		return cached->second;
	}

	
	ll f, s, t;

	if (k == i + 1) {
		f = arr[i].first; s = arr[i].second; t = arr[k].second;
		auto res = f * s*t;
		map.insert({ key,res });
		return res;
	}

	
	ll fres{ 0 };
	ll sres{ 0 };

	if (i != j)
		fres = Solve(arr, i, i, j, map);

	sres = Solve(arr, j+1, j + 1, k, map);
	f = { arr[i].first }; s = { arr[j].second }; t = { arr[k].second };

	auto res = fres + sres + (f*s*t);
	if (j + 1 != k) {
		auto res2 = Solve(arr, i, j + 1, k, map);
		res = min(res, res2);
	}
	map.insert({ key,res });
	return res;
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
		auto marr = new pii[n-1];

		for (int i = 0; i < n-1; i++)
		{
			marr[i] = { arr[i],arr[i + 1] };
		}

		umap_pi map;
		cout << Solve(marr, 0, 0, n - 2 , map) << endl;

	}
								 //code
	return 0;
}