// solved with an unordered_set<int>
// by hxdone

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> t;
        for (int i = 0; i < nums.size(); ++i) {
            if (t.find(nums[i]) != t.end())
                return true;
            else
                t.insert(nums[i]);
        }
        return false;
    }
};
