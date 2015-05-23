#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	// return 0 not palindrome, 1 odd, 2 even
	int isPalindrome(const string& s, int mid) {
		int ret = 0;
		if (!mid) {
			if (s[mid] == s[mid + 1])
				return 2;
			return 1;
		}
		int idx = 0;
		for (idx = 1; idx <= mid; ++idx) {
			if (s[mid - idx] != s[mid + idx])
				break;
		}
		if (idx > mid) ret = 1;
		if (s[mid] != s[mid + 1]) return ret;
		for (idx = 1; idx <= mid; ++idx)
			if (s[mid - idx] != s[mid + idx + 1])
				return ret;
		ret = 2;
		return ret;
	}

	string reverse(const string& s) {
		string ret = s;
		char t;
		int sidx = 0;
		int eidx = s.size() - 1;
		while(sidx < eidx) {
			t = ret[sidx];
			ret[sidx] = ret[eidx];
			ret[eidx] = t;
			++sidx;
			--eidx;
		}
		return ret;
	}

    string shortestPalindrome(string s) {
		string ret;
		string rret;
		int p = 0;
		int mid = (s.size() - 1) / 2;
		while(mid >= 0) {
			p = isPalindrome(s, mid);
			if (p) {
				if (mid == s.size() - 1) return s;
				ret = s.substr(mid);
				if (p == 1) rret = reverse(s.substr(mid + 1));
				else if (p == 2) rret = reverse(s.substr(mid + 2));
				ret = rret + ret;
				return ret;
			}
			--mid;
		}
		return ret;
    }
};

int main()
{
	string str;
    Solution s;
    while(cin>>str) 
    {
		cout << s.shortestPalindrome(str) << endl;
    }
	return 0;
}
