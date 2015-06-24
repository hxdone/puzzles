// by hxdone

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> cur_row;
        if (rowIndex < 0) return cur_row;
        vector<int> last_row;
        last_row.push_back(1);
        for (int i = 1; i <= rowIndex; ++i) {
            cur_row.clear();    
            cur_row.push_back(1);
            for (int j = 1; j < last_row.size(); ++j)
                cur_row.push_back(last_row[j-1]+last_row[j]);
            cur_row.push_back(1);
            last_row.swap(cur_row);
        }
        return last_row;
    }
};
