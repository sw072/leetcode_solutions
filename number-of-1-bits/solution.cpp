#include <iostream>
#include <stdint.h>
using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
		int n1 = 0;
  		while(n) {
			++n1;
			n = (n-1)&n;
		}
		return n1;
    }
};

int main()
{
	Solution s;
	int n;
	while(cin>>n) {
		cout << s.hammingWeight(n) << endl;
	}
	return 0;
}
