// radix sort + counting sort solution by hxdone

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        vector<int> tmp(nums);
        for (int d = 0; d < 32; d+=8) {
            int cnt[256] = {0};
            int mask = 0xff<<d;
            for (int i = 0; i < nums.size(); ++i)
                ++cnt[(nums[i]&mask)>>d];
            for (int i = 1; i < 256; ++i)
                cnt[i] += cnt[i-1];
            for (int i = nums.size()-1; i >=0; --i)
                tmp[--cnt[(nums[i]&mask)>>d]] = nums[i];
            nums.swap(tmp);
        }
        int max_gap =  0;
        for (int i = 1; i < nums.size(); ++i)
            max_gap = max(max_gap, nums[i]-nums[i-1]);
        return max_gap;
    }
};
