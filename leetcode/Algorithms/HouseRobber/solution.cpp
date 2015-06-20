// iterative DP solution by hxdone

class Solution {
public:
	int rob(vector<int>& nums) {
		int* gain = new int[nums.size()+2];
		gain[nums.size()] = 0;
		gain[nums.size()+1] = 0;
		for (int i = nums.size()-1; i >= 0; --i)
			gain[i] = std::max(nums[i]+gain[i+2], gain[i+1]);
		int ret = gain[0];
		delete[] gain;
		return ret;
	}
};
