#include <iostream>
#include <string.h>
using namespace std;

class Solution {
public:
	int squareSum(int n) {
		int sum = 0;
		int digit = 0;
		while(n) {
			digit = n % 10;
			sum += digit * digit;
			n = n / 10;
		}
		return sum;
	}

    bool isHappy(int n) {
		bool mark[100000];
		memset(mark, 0, sizeof(mark));
		int sum = 0;
		while (true) {
			sum = squareSum(n);
			if (sum == 1) return true;
			if (mark[sum]) return false;
			mark[sum] = true;
			n = sum;
		}
    }
};

int main()
{
    int num = 0;
    Solution s;
    while(cin>>num) 
    {
		cout << s.isHappy(num) << endl;
    }
	return 0;
}
