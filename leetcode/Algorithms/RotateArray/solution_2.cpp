// solution 2: rotate by copy and swap.
// by hxdone

class Solution {
public:
	void rotate(vector<int>& nums, int k) {
		k %= nums.size();
		vector<int> nums_new;
		for (int i = nums.size()-k; i < nums.size() ; ++i)
			nums_new.push_back(nums[i]);
		for (int i = 0; i < nums.size()-k; ++i)
			nums_new.push_back(nums[i]);
		nums.swap(nums_new);
	}
};
