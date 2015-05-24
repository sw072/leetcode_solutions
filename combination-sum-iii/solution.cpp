#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

class Solution {
public:
	void _solve(int k, int l, int sum, int c[], vector<vector<int> >&res) {
		if (k == l) {
			if (sum == 0) {
				res.push_back(vector<int>(&c[0], &c[k]));
			}
			return;
		}
		for (int i = c[l - 1] + 1; i <= 9; ++i) {
			if (sum - i < 0) break;
			c[l] = i;
			_solve(k, l + 1, sum - i, c, res);
		}
	}

    vector<vector<int> > combinationSum3(int k, int n) {
		vector<vector<int> > res;
		int c[16];
		memset(c, 0, sizeof(c));
		for (int i = 1; i <= 9; ++i) {
			c[0] = i;
			_solve(k, 1, n - i, c, res);
		}
		return res;
    }
};

int main() {
	int k, n;
	vector<vector<int> > res;
	Solution s;
	while (cin >> k >> n) {
		res = s.combinationSum3(k, n);
		for (int i = 0; i < res.size(); ++i) {
			for (int j = 0; j < res[i].size(); ++j)
				cout << res[i][j] << " ";
			cout << endl;
		}
	}
	return 0;
}
