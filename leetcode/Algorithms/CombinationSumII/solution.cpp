// by hxdone

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ret;
        if (candidates.size() == 0)
            return ret;
        sort(candidates.begin(), candidates.end());
        vector<int> cur_set;
        combinationSum(ret, cur_set, candidates, 0, target);
        return ret;
    }
private:
    void combinationSum(vector<vector<int>>& ret, vector<int>& cur_set, vector<int>& candidates, int idx, int target) {
        if (idx >= candidates.size()) {
            if (target == 0)
                ret.push_back(cur_set);
            return;
        }
        if (target == 0)
            ret.push_back(cur_set);
        else if (target < candidates[idx])
            return;
        else {
            cur_set.push_back(candidates[idx]);
            combinationSum(ret, cur_set, candidates, idx+1, target-candidates[idx]);
            cur_set.pop_back();
            do {
                ++idx;
            } while (idx < candidates.size() && candidates[idx] == candidates[idx-1]);
            combinationSum(ret, cur_set, candidates, idx, target);
        }
    }
};
