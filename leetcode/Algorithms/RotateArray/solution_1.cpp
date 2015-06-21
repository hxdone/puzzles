// solution 1: rotate by reversing
// by hxdone 

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        reverse(nums, 0, nums.size()-k-1);
        reverse(nums, nums.size()-k, nums.size()-1);
        reverse(nums, 0, nums.size()-1);
    }
    
    void reverse(vector<int>& nums, int i, int j) {
        if (i >= j)
            return;
        for (int k = i; k < (i+j+1)/2; ++k) {
            int tmp = nums[k];
            nums[k] = nums[j+i-k];
            nums[j+i-k] = tmp;
        }
    }
};
