#include <vector>
#include <tuple>

namespace Helpers {

	vector<pair<int, int>> GetAdjacent(int i, int j, int& n, int& m) {
		vector < pair<int, int>> v;
		if (i - 1 >= 0) {
			v.push_back({ i - 1,j });
		}
		if (i - 1 >= 0 && j - 1 >= 0) {
			v.push_back({ i - 1,j - 1 });
		}
		if (i - 1 >= 0 && j + 1 < m) {
			v.push_back({ i - 1,j + 1 });
		}
		if (j - 1 >= 0) {
			v.push_back({ i,j - 1 });
		}
		if (j + 1 < m) {
			v.push_back({ i,j + 1 });
		}
		if (i + 1 < n) {
			v.push_back({ i + 1,j });
			if (j + 1 < m) {
				v.push_back({ i + 1,j + 1 });
			}
			if (j - 1 >= 0) {
				v.push_back({ i + 1,j - 1 });
			}
		}

		return v;
	}
}