// Iterative solution by hxdone

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        else if (nums.size() == 1)
            return nums[0];
        else if (nums.size() == 2)
            return max(nums[0], nums[1]);
        int* gain_1 = new int[nums.size()];// for vector ending with nums[nums.size()-2]
        int* gain_2 = new int[nums.size()];// for vector ending with nums[nums.size()-1]
        gain_1[nums.size()-1] = 0;
        gain_1[nums.size()-2] = nums[nums.size()-2];
        gain_2[nums.size()-1] = nums[nums.size()-1];
        gain_2[nums.size()-2] = max(nums[nums.size()-2], nums[nums.size()-1]);
        for (int i = (int)(nums.size())-3; i >= 2; --i) {
            // gain_x[i] = max(nums[i]+gain_x[i+2], gain_x[i+1]);
            gain_1[i] = max(nums[i]+gain_1[i+2], gain_1[i+1]);
            gain_2[i] = max(nums[i]+gain_2[i+2], gain_2[i+1]);
        }
        if (nums.size() > 3)
            gain_2[1] = max(nums[1]+gain_2[3], gain_2[2]);
        
        int ret = max(nums[0]+gain_1[2], gain_2[1]);
        delete[] gain_1;
        delete[] gain_2;
        return ret;
    }
};
