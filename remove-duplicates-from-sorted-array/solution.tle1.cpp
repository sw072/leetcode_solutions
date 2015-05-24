#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	// backward
    int removeDuplicates(vector<int>& nums) {
		if (nums.size() == 0) return 0;
		int s = 0, e = nums.size(), g = 0, nl = nums.size();
		while (s >= 0) {
			s = e - 1;
			while (nums[s] == nums[e] && s >= 0) --s;
			g = e - s - 1;
			while (g && e < nl) {
				nums[e - g] = nums[e];
				e++;
			}
			nl = nl - g;
			e = s;
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
