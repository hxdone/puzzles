// by hxdone

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() < 2) return;
        int i;
        for (i = nums.size()-2; i >= 0 && nums[i] >= nums[i+1]; --i);
        if (i < 0)
            reverse(nums, 0, nums.size()-1);
        else {
            reverse(nums, i+1, nums.size()-1);
            auto iter = upper_bound(nums.begin()+(i+1), nums.end(), nums[i]);
            int t = *iter;
            *iter = nums[i];
            nums[i] = t;
        }
    }
private:
    void reverse(vector<int>& nums, int i, int j) {
        while (i < j) {
            int t = nums[i];
            nums[i++] = nums[j];
            nums[j--] = t;
        }
    }
};
