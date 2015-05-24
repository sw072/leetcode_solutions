#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	
	void _generator(int s, int n, int l, int nn, char c[], vector<string>& res) {
		if (l == 0) {
			// one compositior
			c[nn] = '\0';
			res.push_back(string(c));
			return;
		}
		if (s >= 0) {
			if (n > 0) {
				c[nn-l] = '(';
				_generator(s + 1, n - 1, l - 1, nn, c, res);
			}
			if (s > 0) {
				c[nn-l] = ')';
				_generator(s - 1, n, l - 1, nn, c, res);
			}
		}
	}

    vector<string> generateParenthesis(int n) {
		vector<string> res;
		char c[64];
		_generator(0, n, n << 1, n << 1, c, res);
		return res;
    }
};

int main() {
	int n;
	vector<string> res;
	Solution s;
	while(cin>>n) {
		res = s.generateParenthesis(n);
		for (int idx = 0; idx < res.size(); ++idx)
			cout << res[idx] << " ";
		cout << endl;
	}
	return 0;
}
