#include <iostream>
#include <stdint.h>
using namespace std;

class Solution {
public:
	int _reverse(int res, int x) {
		if (!x) return res;
		int t = res * 10 + x % 10;
		if ((t - x % 10) / 10 != res) return 0;
		res = t;
		return _reverse(res, x / 10);
	}

    int reverse(int x) {
		if (x < 0) return -1 * _reverse(0, -x);
		return _reverse(0, x);
    }
};

int main()
{
    uint32_t num = 0;
    Solution s;
    while(cin>>num) 
    {
		cout << s.reverse(num) << endl;
    }
	return 0;
}
