// backtracking solution by hxdone

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ret;
        if (nums.size() == 0)
            return ret;
        vector<int> cur_perm(nums);
        sort(cur_perm.begin(), cur_perm.end());
        permute(ret, cur_perm, 0);
        return ret;
    }
private:
    void permute(vector<vector<int>>& ret, vector<int>& cur_perm, int i) {
        if (i == cur_perm.size()-1)
            ret.push_back(cur_perm);
        else {
            sort(cur_perm.begin()+i, cur_perm.end());
            for (int j = i; j < cur_perm.size(); ++j) {
                if (j != i && (cur_perm[j] == cur_perm[j-1]))
                    continue;
                int tmp = cur_perm[j];
                for (int k = j-1; k >= i; --k)
                    cur_perm[k+1] = cur_perm[k];
                cur_perm[i] = tmp;
                
                permute(ret, cur_perm, i+1);
                tmp = cur_perm[i];
                for (int k = i+1; k <= j; ++k)
                    cur_perm[k-1] = cur_perm[k];
                cur_perm[j] = tmp;
            }
        }
    }
};
