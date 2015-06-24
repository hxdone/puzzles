// by hxdone

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < board.size(); ++i) {
            int mask_row = 0, mask_col = 0; 
            for (int j = 0; j < board.size(); ++j) {
                if (board[i][j] != '.') {
                    int digit = board[i][j]-'0'; 
                    if ((1<<digit)&mask_row)
                        return false;
                    else
                        mask_row |= (1<<digit); 
                }
                if (board[j][i] != '.') {
                    int digit = board[j][i]-'0'; 
                    if ((1<<digit)&mask_col)
                        return false;
                    else
                        mask_col |= (1<<digit); 
                }
            }
        }
        for (int i = 0; i < 9; i+=3) {
            for (int j = 0;  j < 9; j+=3) {
                int mask = 0;
                for (int k = 0; k < 3; ++k) {
                    for(int m = 0; m < 3; ++m) {
                        if (board[i+k][j+m]  != '.') {
                            int digit = board[i+k][j+m];
                            if ((1<<digit)&mask)
                                return false;
                            else
                                mask |= (1<<digit); 
                        }
                    }
                }
            }
        }
        return true;
    }
};
