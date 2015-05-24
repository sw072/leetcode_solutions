#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
		if (nums.size() == 0) return 0;
		int s = 0, e = nums.size(), idx = 0;
		idx = s + 1;
		while (idx < e) {
			while (nums[idx] == nums[s] && idx < e) ++idx;
			if (idx == e) break;
			if (idx - s > 1) nums[s+1] = nums[idx];
			++s;
			++idx;
		}
		return s + 1;
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
