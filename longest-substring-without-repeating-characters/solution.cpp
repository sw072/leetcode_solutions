#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
		int max_nr = 0;
		int curr_nr = 0;
		int start_pos = 0;
		int mark[256];
		memset(mark, 0, sizeof(mark));
		for (int idx = 0; idx < s.size(); ++idx) {
			if (mark[s[idx]]) {
				if (curr_nr > max_nr) max_nr = curr_nr;
				while (s[start_pos] != s[idx]) {
					mark[s[start_pos]] = 0;
					start_pos++;
					curr_nr--;
				}
				start_pos++;
				continue;
			}
			mark[s[idx]] = 1;
			curr_nr++;
		}
		if (curr_nr > max_nr) max_nr = curr_nr;
		return max_nr;
    }
};

int main()
{
	string str;
    Solution s;
    while(cin>>str) 
    {
		cout << s.lengthOfLongestSubstring(str) << endl;
    }
	return 0;
}
