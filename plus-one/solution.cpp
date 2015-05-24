#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
		int carry = 0;
		vector<int> res = digits;
		res[digits.size() - 1] = (digits[digits.size() - 1] + 1) % 10;
		carry = (digits[digits.size() - 1] + 1) / 10;
		for (int idx = digits.size() - 2; idx >= 0; --idx) {
			res[idx] = (digits[idx] + carry) % 10;
			carry = (digits[idx] + carry) / 10;
		}
		if (carry) res.insert(res.begin(), 1);
		return res;
    }
};

int main () {
	int n;
	vector<int> digits;
	while (cin >> n) {
		digits.push_back(n);
	}
	Solution s;
	digits = s.plusOne(digits);
	for (int idx = 0; idx < digits.size(); ++idx) {
		cout << digits[idx];
	}
	cout << endl;

	return 0;
}
