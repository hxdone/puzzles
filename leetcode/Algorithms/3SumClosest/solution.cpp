// by hxdone

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if (nums.size() < 3)
            return 0;
        int sum = nums[0]+nums[1]+nums[2];
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size()-2; ++i) {
            if (i > 0 && nums[i] == nums[i-1]) continue;
            int j = i+1;
            int k = nums.size()-1;
            while (j < k) {
                int new_sum = nums[i]+nums[j]+nums[k];
                if (new_sum == target)
                    return target;
                if (abs(target-new_sum) < abs(target-sum))
                    sum = new_sum;
                if (new_sum < target)
                    ++j;
                else --k;
            }   
        }   
        return sum;
    }   
};
