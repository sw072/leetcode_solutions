#include <iostream>
#include <stdint.h>
#include <limits.h>
using namespace std;

class Solution {
public:
    int myAtoi(string str) {
		int sig = 1;
		int idx = 0;
		while(str[idx] == ' ') {
			++idx;
		}
		if (str[idx] == '-') {
			sig = -1;
			idx++;
		} else if (str[idx] == '+') {
			sig = 1;
			idx++;
		}
		int bound = str.size();
		int sum = 0, t = 0;
		while(idx < bound) {
			if (str[idx] < '0' || str[idx] > '9') return sum * sig;
			t = sum * 10 + (str[idx] - '0');
			if (((t - (str[idx] - '0')) / 10) != sum || t < 0) {
				if (sig == 1) {
					return INT_MAX;
				}
				return INT_MIN;
			}
			sum = t;
			++idx;
		}
		return sum * sig;
    }
};

int main()
{
	string str;
    Solution s;
    while(cin>>str) 
    {
		cout << s.myAtoi(str) << endl;
    }
	return 0;
}
