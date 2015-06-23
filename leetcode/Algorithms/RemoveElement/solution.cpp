// by hxdone

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int pos_to_insert = 0;
        for (int i = 0; i < nums.size(); ++i)
            if (nums[i] != val)
                nums[pos_to_insert++] =  nums[i];
        return pos_to_insert;
    }
};
