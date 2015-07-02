// by hxdone

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.size() == 0 || obstacleGrid[0].size() == 0)
            return 0;
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> num_paths;
        for (int i = 0; i <= m; ++i) {
            vector<int> v;
            for (int j = 0; j <= n; ++j)
                v.push_back(0);
            num_paths.push_back(v);
        }

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (i == 1 && j == 1) {
                    if (obstacleGrid[i-1][j-1])
                        return 0;
                    else
                        num_paths[i][j] = 1;
                } else
                    num_paths[i][j] = obstacleGrid[i-1][j-1] ? 0 : num_paths[i-1][j]+num_paths[i][j-1];
            }
        }
        return num_paths[m][n];
    }
};
