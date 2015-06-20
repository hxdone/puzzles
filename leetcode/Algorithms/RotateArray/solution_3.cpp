// solution 3: real rotation.
// by hxdone

class Solution {
public:
	void rotate(vector<int>& nums, int k) {
		k %= nums.size();
		for (int i = 0; i < k; ++i) {
			int tmp = nums.back();
			nums.pop_back();
			nums.insert(nums.begin(), tmp);
		}
	}
};
