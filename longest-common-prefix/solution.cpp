#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
		if (strs.size() == 0) return "";
		if (strs.size() == 1) return strs[0];
        int idx = 0, i = 0;
		int minLen = 2147483647;
		bool term = false;
		for (idx = 0; idx < strs.size(); ++idx)
			if (strs[idx].size() < minLen) minLen = strs[idx].size();
		for (idx = 0; idx < minLen && !term; ++idx) {
			for (i = 1; i < strs.size(); ++i) {
				if (strs[i][idx] != strs[0][idx]) {
					term = true;
					break;
				}
			}
			if (term) break;
		}
		return strs[0].substr(0, idx);
    }
};

int main()
{
    vector<string> strs;
	string str;
    while(cin>>str) 
    {
		strs.push_back(str);
    }
    Solution s;
    cout << s.longestCommonPrefix(strs) << endl;
}
