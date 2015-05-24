#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	string _count(const string& last) {
		static char next[2048];
		int p = 0;
		int s = 0, e = last.size(), idx = 0;
		idx = s + 1;
		while (s < e) {
			while (last[idx] == last[s] && idx < e) ++idx;
			next[p++] = '0' + (idx - s);
			next[p++] = last[s];
			s = idx;
			++idx;
		}
		next[p] = 0;
		return string(next);
	}

    string countAndSay(int n) {
		if (n == 1) return "1";
		string str[2];
		str[0] = "1";
		int idx = 1;
		while (idx < n) {
			str[idx % 2] = _count(str[(idx - 1) % 2]);
			++idx;
		}
		return str[(idx - 1) % 2];
    }
};

int main() {
	int num;
	Solution s;
	while (cin>>num) {
		cout << s.countAndSay(num) << endl;
	}
	return 0;
}
