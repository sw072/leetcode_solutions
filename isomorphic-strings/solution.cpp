#include <iostream>
#include <string>
#include <string.h>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
		char mapping[256];
		bool mark[256];
		memset(mapping, 0, sizeof(mapping));
		memset(mark, 0, sizeof(mark));
		for (int idx = 0; idx < s.size(); ++idx)
		{
			if (!mapping[s[idx]] && !mark[t[idx]]) {
				mapping[s[idx]] = t[idx];
				mark[t[idx]] = true;
			} else {
				if (mapping[s[idx]] != t[idx]) return false;
			}
		}
		return true;
    }
};

int main()
{
	string ss, st;
    Solution s;
    while(cin>>ss) 
    {
		if (ss == string("-1")) break;
		cin>>st;
		cout << s.isIsomorphic(ss, st) << endl;
    }
	return 0;
}
