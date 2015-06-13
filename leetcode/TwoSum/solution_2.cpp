// Solve it with unordered_map.
// author: hxdone

#include<iostream>
#include<map>
#include<vector>
using namespace std;

class Solution {
public:
	typedef map<int, int> kv_map; // value is largest element index for key
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> ret;
		// add nums to a hash table
		int cnt = nums.size();
		kv_map value_map;
		kv_map::iterator iter;
		for (int i = 0; i < cnt; ++i)
			value_map[nums[i]] = i;
		// find the diff value in hash table
		for (int i = 0; i < cnt; ++i) {
			iter = value_map.find(target-nums[i]);
			if (iter != value_map.end() && iter->second != i) {
				ret.push_back(i+1);
				ret.push_back(iter->second+1);
				return ret;
			}
		}
		return ret;
	}

};

int main() {
	vector<int> nums;
	nums.push_back(0);
	nums.push_back(4);
	nums.push_back(2);
	nums.push_back(3);
	nums.push_back(0);
	int target = 7;

	cout << "[";
	for(int i = 0; i < nums.size(); ++i)
		cout << nums[i] << ", ";
	cout << "] => " << target << endl;

	vector<int> result = Solution().twoSum(nums, target);
	for(int i = 0; i < result.size(); ++i)
		cout << result[i] << endl;
	return 0;
}
