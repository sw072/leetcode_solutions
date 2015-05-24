#include <iostream>
#include <string>
#include <string.h>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
		const char *h = haystack.c_str();
		const char *n = needle.c_str();
		const char *r = strstr(h, n);
		if (!r) return -1;
		return (int)(r - h);
    }
};

int main() {
	string str1, str2;
	Solution s;
	while(cin>>str1) {
		cin>>str2;
		cout << s.strStr(str1, str2) << endl;
	}
	return 0;
}
