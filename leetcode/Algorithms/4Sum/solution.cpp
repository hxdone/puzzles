// by hxdone

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ret;
        if (nums.size() < 4)
            return ret;
        sort(nums.begin(), nums.end());
        for (int first = 0; first < nums.size()-3; ++first) {
            if (first != 0 && nums[first] == nums[first-1])
                continue;
            for (int second = first+1; second < nums.size()-2; ++second) {
                if (second != first+1 && nums[second] == nums[second-1])
                    continue;
                int third = second+1;
                int fourth = nums.size()-1;
                while (third < fourth) {
                    int sum = nums[first]+nums[second]+nums[third]+nums[fourth];
                    if (sum == target) {
                        vector<int> v = {nums[first],nums[second],nums[third],nums[fourth]};
                        ret.push_back(v);
                        do {
                            ++third;
                        } while (third != second+1 && nums[third] == nums[third-1]);
                    } else if (sum < target) {
                        do {
                            ++third;
                        } while (third != second+1 && nums[third] == nums[third-1]);
                    } else {
                        do {
                            --fourth;
                        } while (fourth != nums.size()-1 && nums[fourth] == nums[fourth+1]);
                    }
                }
            }
        }
        return ret;
    }
};
