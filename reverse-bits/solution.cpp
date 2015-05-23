#include <iostream>
#include <stdint.h>
using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
		uint32_t rn = 0, m = 0;
        for (int idx = 0; idx < 32; ++idx) {
			m = n & ((uint32_t)1 << (32 - idx - 1));
			if (idx < 16) m = m >> (31 - (idx << 1));
			else m = m << ((idx << 1) - 31);
			rn = rn | m;
		}
		return rn;
    }
};

int main()
{
    uint32_t num = 0;
    Solution s;
    while(cin>>num) 
    {
		cout << s.reverseBits(num) << endl;
    }
	return 0;
}
