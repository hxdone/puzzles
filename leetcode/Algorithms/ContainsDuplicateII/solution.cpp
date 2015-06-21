// by hxdone

class Solution {
public:
	bool containsNearbyDuplicate(vector<int>& nums, int k) {
		unordered_set<int> t;
		for (int i = 0; i < std::min((int)nums.size(), k+1); ++i) {
			if (t.find(nums[i]) != t.end())
				return true;
			else
				t.insert(nums[i]);
		}
		for (int i = k+1; i < nums.size(); ++i) {
			t.erase(nums[i-k-1]);
			if (t.find(nums[i]) != t.end())
				return true;
			else
				t.insert(nums[i]);
		}
		return false;
	}
};
