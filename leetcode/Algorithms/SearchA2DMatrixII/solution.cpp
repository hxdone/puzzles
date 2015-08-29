// solution by hxdone

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        return searchMatrix(matrix, 0, 0, m-1, n-1, target);
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int start_x, int start_y, int end_x, int end_y, int target) {
        // search the diagonal line of submatrix
        if (start_x > end_x || start_y > end_y)
            return false;
        int low = 0;
        int high = std::min(end_x-start_x, end_y-start_y);
        while (low <= high) {
            int mid = (low+high)/2;
            int cur_val = matrix[start_x+mid][start_y+mid];
            if (cur_val == target)
                return true;
            else if (cur_val < target)
                low = mid+1;
            else
                high = mid-1;
        }
        return searchMatrix(matrix, start_x, start_y+low, start_x+high, end_y, target)
                || searchMatrix(matrix, start_x+low, start_y, end_x, start_y+high, target);
    }
};
