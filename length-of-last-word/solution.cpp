#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
		int st = -1, e = s.size(), idx = 0;
		while (s[e - 1] == ' ') e--; 
		while (idx < e) {
			while (s[idx] != ' ' && idx < e) ++idx;
			if (idx == e) break;
			st = idx + 1;
			++idx;
		}
		if (st == -1) return e;
		return e- st;
    }
};


int main() {
	Solution s;
	cout << s.lengthOfLastWord(" a ") << endl;
	return 0;
}
