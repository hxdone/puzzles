// O(lg(m)+lg(n)) solution by hxdone

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int low = 0;
        int high = m-1;
        while (low <= high) {
            int mid = (low+high)/2;
            if (matrix[mid][0] == target)
                return true;
            else if (matrix[mid][0] < target)
                low = mid+1;
            else
                high = mid-1;
        }
        if (high < 0)
            return false;
        int row = high;
        low = 1;
        high = n-1;
        while (low <= high) {
            int mid = (low+high)/2;
            if (matrix[row][mid] == target)
                return true;
            else if (matrix[row][mid] < target)
                low = mid+1;
            else
                high = mid-1;
        }
        return false;
    }
};
