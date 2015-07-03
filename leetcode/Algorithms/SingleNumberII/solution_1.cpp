// %3 for each bit
// by hxdone

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int bit_cnt[32] = {0};
        for (int i = 0; i < nums.size(); ++i)
            for (int j = 0; j < 32; ++j) {
                bit_cnt[j] += (nums[i]&(1<<j))? 1:0;
                bit_cnt[j] %= 3;
            }
        int ret = 0;
        for (int i = 0; i < 32; ++i)
            ret |= bit_cnt[i]?(1<<i):0;
        return ret;
    }
};
