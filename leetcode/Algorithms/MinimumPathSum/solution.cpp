// iterative DP solution by hxdone

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.size() == 0 || grid[0].size() == 0)
            return 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> path_sum;
        for (int i = 0; i < m; ++i) {
            vector<int> v;
            for (int j = 0; j < n; ++j)
                v.push_back(0);
            path_sum.push_back(v);
        }
        for (int i = m-1; i >= 0; --i)
            for (int j = n-1; j >= 0; --j) {
                if (i+1 < m)
                    path_sum[i][j] = grid[i][j] + (j+1>=n ? path_sum[i+1][j]: min(path_sum[i+1][j], path_sum[i][j+1]));
                else
                    path_sum[i][j] = grid[i][j] + (j+1>=n ? 0 : path_sum[i][j+1]);
            }
        return path_sum[0][0];
    }
};
