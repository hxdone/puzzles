// O(n) solution with a diff counter
// by hxdone

class Solution {
public:
	int majorityElement(vector<int>& nums) {
		int n1 = nums[0];
		int n1_cnt = 1;
		for (int i = 1; i < nums.size(); ++i) {
			if (n1_cnt == 0) {
				n1 = nums[i];
				n1_cnt = 1;
				continue;
			}
			if (nums[i] == n1)
				++n1_cnt;
			else
				--n1_cnt;
		}
		return n1;
	}
};
