#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
	sort(nums.begin(), nums.end());
	k = nums.size() - k;
	if (k < 0) k = 0;
	return nums[k];
    }
};

int main()
{
    vector<int> nums;
    int num = 0;
    while(cin>>num) 
    {
	nums.push_back(num);
    }
    Solution s;
    cout << s.findKthLargest(nums, 2) << endl;
}
