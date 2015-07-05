// breadth-first traverse of a graph
// by hxdone

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        if (m == 0 || grid[0].size() == 0)
            return 0;
        int n = grid[0].size();
        vector<vector<bool>> visited;
        for (int i = 0; i < m; ++i) {
            visited.push_back(vector<bool>());
            for (int j = 0; j < n; ++j)
                visited[i].push_back(false);
        }
        
        int ret = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (!visited[i][j] && grid[i][j] == '1') {
                    ++ret;
                    // breadth-first traverse
                    queue<pair<int,int>> pos_queue;
                    visited[i][j] = true;
                    pos_queue.push(pair<int,int>(i,j));
                    while (!pos_queue.empty()) {
                        pair<int,int> pos = pos_queue.front();
                        pos_queue.pop();
                        if (pos.first > 0 && !visited[pos.first-1][pos.second]
                            && grid[pos.first-1][pos.second] == '1') {
                            visited[pos.first-1][pos.second] = true;
                            pos_queue.push(pair<int,int>(pos.first-1,pos.second));
                        }
                        if (pos.first < m-1 && !visited[pos.first+1][pos.second]
                            && grid[pos.first+1][pos.second] == '1') {
                            visited[pos.first+1][pos.second] = true;
                            pos_queue.push(pair<int,int>(pos.first+1,pos.second));
                        }
                        if (pos.second > 0 && !visited[pos.first][pos.second-1]
                            && grid[pos.first][pos.second-1] == '1') {
                            visited[pos.first][pos.second-1] = true;
                            pos_queue.push(pair<int,int>(pos.first,pos.second-1));
                        }
                        if (pos.second < n-1 && !visited[pos.first][pos.second+1]
                            && grid[pos.first][pos.second+1] == '1') {
                            visited[pos.first][pos.second+1] = true;
                            pos_queue.push(pair<int,int>(pos.first,pos.second+1));
                        }
                    }
                }
            }
        }
        
        return ret;
    }
};
