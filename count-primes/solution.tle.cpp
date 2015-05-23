#include <iostream>
#include <math.h>
using namespace std;

class Solution {
public:
	bool isPrime(int n) {
		if (n == 2) return true;
		int q = (int)sqrt(n) + 1;
		for (int d = 2; d <= q; ++d) {
			if (n % d == 0) return false;
		}
		return true;
	}

    int countPrimes(int n) {
		int ret = 0;
		if (n <= 1) return 0;
		--n;
		while(n > 1) {
			if (isPrime(n)) {
				ret++;
			}
			--n;
		}
		return ret;
    }
};

int main()
{
    int num = 0;
    Solution s;
    while(cin>>num) 
    {
		cout << s.countPrimes(num) << endl;
    }
	return 0;
}
