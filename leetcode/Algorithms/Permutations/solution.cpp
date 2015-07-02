// swapping and recursion solution by hxdone

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ret;
        if (nums.size() == 0)
            return ret;
        vector<int> cur_perm(nums);
        permute(ret, cur_perm, 0);
        return ret;
    }
private:
    void permute(vector<vector<int>>& ret, vector<int>& cur_perm, int i) {
        if (i == cur_perm.size()-1)
            ret.push_back(cur_perm);
        else {
            for (int j = i; j < cur_perm.size(); ++j) {
                swap(cur_perm, i, j);
                permute(ret, cur_perm, i+1);
                swap(cur_perm, i, j);
            }
        }
    }
    
    inline void swap(vector<int>& cur_perm, int i, int j) {
        if (i != j) {
            int tmp = cur_perm[i];
            cur_perm[i] = cur_perm[j];
            cur_perm[j] = tmp;
        }
    }
};
