#include <iostream>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
		char sum[1024];
		int carry = 0;
		string t;
		if (a.size() < b.size()) {
			t = a;
			a = b;
			b = t;
		}
		int pa = a.size() - 1;
		int pb = b.size() - 1;
		sum[pa + 1] = '\0';
		for (; pa >= 0 && pb >= 0; --pa, --pb) {
			sum[pa] = (a[pa] + b[pb] + carry - 2 * '0') % 2 + '0';
			carry = (a[pa] + b [pb] + carry - 2 * '0') / 2;
		}
		for (; pa >= 0; --pa) {
			sum[pa] = (a[pa] + carry - '0') % 2 + '0';
			carry = (a[pa] + carry - '0') / 2;
		}
		if (carry) return "1" + string(sum);
		return string(sum);
    }
};

int main() {
	string str1, str2;
	Solution s;
	while (cin >> str1 >> str2) {
		cout << s.addBinary(str1, str2) << endl;
	}
	return 0;
}
