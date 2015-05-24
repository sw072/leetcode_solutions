#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
		if (nums.size() == 0) return 0;
		int s = -1, e = nums.size(), idx = 0;
		idx = s + 1;
		while (idx < e) {
			while (nums[idx] == val && idx < e) ++idx;
			if (idx == e) break;
			nums[s+1] = nums[idx];
			++s;
			++idx;
		}
		return s + 1;
    }
};

int main() {
	int n, val;
	vector<int> nums;
	Solution s;
	while (cin >> n) {
		if (n == -1) {
			cin >> val;
			int nl = s.removeElement(nums, val);
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
