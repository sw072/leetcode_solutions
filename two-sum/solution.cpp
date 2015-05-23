#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> ret;
		map<int, int> v2p;
		int pos = 1;
		for (vector<int>::iterator iter = nums.begin(); iter != nums.end(); ++iter, ++pos)
		{
			v2p[*iter] = pos;
		}   
		int r = 0;
		map<int, int>::iterator riter;
		pos = 1;
		for (vector<int>::iterator iter = nums.begin(); iter != nums.end(); ++iter, ++pos)
		{
			r = target - *iter;
			riter = v2p.find(r);
			if (riter != v2p.end() && riter->second != pos)
			{
				ret.push_back(pos);
				ret.push_back(riter->second);
				break;
			}
		}
		return ret;
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
    vector<int> ret = s.twoSum(nums, 6);
	for (int idx = 0; idx < ret.size(); ++idx)
		cout << ret[idx] << endl;
}
