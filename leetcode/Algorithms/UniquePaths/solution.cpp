// iterative DP solution by hxdone

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> num_paths;
        for (int i = 0; i <= m; ++i) {
            vector<int> v;
            for (int j = 0; j <= n; ++j)
                v.push_back(0);
            num_paths.push_back(v);
        }
        
        for (int i = 1; i <= m; ++i)
            for (int j = 1; j <= n; ++j) {
                if (i == 1 && j == 1)
                    num_paths[i][j] = 1;
                else
                    num_paths[i][j] = num_paths[i-1][j]+num_paths[i][j-1];
            }
        return num_paths[m][n];
    }
};
