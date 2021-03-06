// TwoWaterJugProblem.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

//Wrong code never completed it.

int SolveInternal(int cm, int cn, int m, int n, int d, int movedFrom ,int op) {
	if (cm == d || cn == d) return op;
	if (cm + cn == d) return op + 1;
	if (cm == m && cn == n) return -1;
	if (cm == 0 && cn == 0 && op > 0) return -1;
	int res = -1;

	
	//move from cm to cn and recurse
	if(cm>0 && cn < n && movedFrom != 2){
		int maxFill = n - cn;
		int toMove = min(maxFill, cm);
		auto tres = SolveInternal(cm - toMove, cn + toMove, m, n, d, 1 ,op + 1);
		if (tres != -1) {
			res = res = -1 ? tres : min(res, tres);
		}
	}

	//move from cn to cm and recurse 
	if (cn >0 && cm < m &&  movedFrom != 1) {
		int maxFill = m - cm;
		int toMove = min(maxFill, cn);
		auto tres = SolveInternal(cm + toMove, cn - toMove, m, n, d, 1 ,op + 1);
		if (tres != -1) {
			res = res = -1 ? tres : min(res, tres);
		}
	}

	if (cm != m && cn != n) {
		//fill cm and recurse
		auto tres = SolveInternal(m, cn, m, n, d, -1 ,op + 1);
		if (tres != -1) {
			res = res = -1 ? tres : min(res, tres);
		}
	}
	if (cn != n && cm!=m) { //fill n and recurse
		auto tres = SolveInternal(cm, n, m, n, d, -1 ,op + 1);
		if (tres != -1) {
			res = res = -1 ? tres : min(res, tres);
		}
	}

	if (cm != 0 && cn != n) { // empty and recurse
		auto tres = SolveInternal(0, cn, m, n, d, -1, op + 1);
		if (tres != -1) {
			res = res = -1 ? tres : min(res, tres);
		}
	}
	
	if (cn != 0 && cm !=m) { // empty and recurse
		auto tres = SolveInternal(cm, 0, m, n, d, -1, op + 1);
		if (tres != -1) {
			res = res = -1 ? tres : min(res, tres);
		}
	}


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
		int m, n, d;
		cin >> m >> n >> d;
		cout << SolveInternal(0, 0, m, n, d, -1 , 0) << endl;
	}

	return 0;
}