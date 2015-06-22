// by hxdone

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        int pos_to_add = 1;
        int last = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] != last) {
                nums[pos_to_add++] = nums[i];
                last = nums[i];
            }
        }
        return pos_to_add;
    }
}; 
