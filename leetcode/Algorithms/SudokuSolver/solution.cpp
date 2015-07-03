// backtracking solution using recursion
// by hxdone

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        vector<int> row_mask;
        vector<int> col_mask;
        vector<vector<int>> zone_mask;
        
        for (int i = 0; i < 9; ++i) {
            row_mask.push_back(0x3fe);
            col_mask.push_back(0x3fe);
            if (i%3 == 0)
                zone_mask.push_back(vector<int>());
            zone_mask[(int)zone_mask.size()-1].push_back(0x3fe);
        }
        
        vector<pair<int,int>> pos_to_fill;
        for (int i = 0; i < 9; ++i)
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.')
                    pos_to_fill.push_back(pair<int,int>(i,j));
                else {
                    int num = board[i][j]-'0';
                    int bit_mask = ~(1<<num);
                    row_mask[i] &= bit_mask;
                    col_mask[j] &= bit_mask;
                    zone_mask[i/3][j/3] &= bit_mask;
                }
            }
        
        // backtracking by recursion
        try_next(board, pos_to_fill, 0, row_mask, col_mask, zone_mask);
    }
private:

    bool try_next(vector<vector<char>>& board, vector<pair<int, int>>& pos_list, int idx, vector<int>& row_mask, vector<int>& col_mask, vector<vector<int>>& zone_mask) {
        if (idx > (int)pos_list.size()-1)
            return true;
        pair<int, int> pos = pos_list[idx];
        int i = pos.first;
        int j = pos.second;
        int mask = row_mask[i]&col_mask[j]&zone_mask[i/3][j/3];
        for (int num = 1; num <= 9; ++num) {
            int bit_mask = 1<<num;
            if (mask&bit_mask) {
                board[i][j] = '0'+num;
                row_mask[i] &= ~bit_mask;
                col_mask[j] &= ~bit_mask;
                zone_mask[i/3][j/3] &= ~bit_mask;
                bool ret = try_next(board, pos_list, idx+1, row_mask, col_mask, zone_mask);
                if (ret)
                    return true;
                else {
                    board[i][j] = '.';
                    row_mask[i] |= bit_mask;
                    col_mask[j] |= bit_mask;
                    zone_mask[i/3][j/3] |= bit_mask;
                }
            }
        }
        return false;
    }
};
