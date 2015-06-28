// map solution by hxdone

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        map<int, int> vmap;
        for (int i = 0; i < nums.size(); ++i) {
            auto iter = vmap.lower_bound(nums[i]);
            if (iter != vmap.end() && (long)(iter->first)-nums[i] <= t)
                return true;
            if (iter != vmap.begin() && (long)nums[i]-((--iter)->first) <= t)
                return true;
            vmap[nums[i]]++;
            
            if (i >= k) {
                if (vmap[nums[i-k]] <= 1)
                    vmap.erase(nums[i-k]);
                else
                    vmap[nums[i-k]]--;
            }
        }
        return false;
    }
};
