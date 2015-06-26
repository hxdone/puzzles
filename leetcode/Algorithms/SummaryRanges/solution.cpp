// by hxdone

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ret;
        if (nums.size() == 0) return ret;
        int start = 0;
        int end;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] != nums[i-1]+1) {
                end = i-1;
                ret.push_back(start==end ? to_string(nums[start]) : to_string(nums[start]).append("->").append(to_string(nums[end])) );
                start = i;
            }
        }
        end = nums.size()-1;
        ret.push_back(start==end ? to_string(nums[start]) : to_string(nums[start]).append("->").append(to_string(nums[end])) );
        return ret;
    }
};
