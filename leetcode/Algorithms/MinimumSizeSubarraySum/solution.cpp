// O(n) solution by hxdone

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        int start = 0;
        int end = -1;
        int sum = 0;
        int len = nums.size()+1;
        while (true) {
            if (sum < s) {
                if (++end < nums.size())
                    sum += nums[end];
                else break;
            } else {
                len = min(len, end-start+1);
                sum -= nums[start++];
            }
        }
        return (len == nums.size()+1) ? 0 : len;
    }
};
