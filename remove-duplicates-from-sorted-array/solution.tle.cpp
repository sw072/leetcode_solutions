#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
		int s = 0, e = 0, g = 0, nl = nums.size();
		while (s < nl - 1) {
			e = s + 1;
			while (nums[e] == nums[s] && e < nl) ++e;
			g = e - s - 1;
			while (g && e < nl) {
				nums[e - g] = nums[e];
				e++;
			}
			nl = nl - g;
			++s;
		}
		return nl;
    }
};

int main() {
	int n;
	vector<int> nums;
	Solution s;
	while (cin >> n) {
		if (n == 100000) {
			int nl = s.removeDuplicates(nums);
			cout << nl << endl;
			for (int idx = 0; idx < nl; ++idx) {
				cout << nums[idx] << " ";
			}
			cout << endl;
			nums.clear();
			continue;
		}
		nums.push_back(n);
	}
	return 0;
}
