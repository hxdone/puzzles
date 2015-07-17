// by hxdone

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ret;
        if (nums.size() == 0)
            return ret;
        else
            ret.push_back(1);
        for (int i = 1; i < nums.size(); ++i)
            ret.push_back(nums[i-1]*ret[i-1]);
        int back_product = 1;
        for (int i = (int)(nums.size())-2; i >= 0; --i) {
            back_product *= nums[i+1];
            ret[i] *= back_product;
        }
        return ret;
    }
};
