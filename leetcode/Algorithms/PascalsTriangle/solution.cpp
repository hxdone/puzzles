// by hxdone

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ret;
        if (numRows < 1)
            return ret;
        vector<int> v0;
        v0.push_back(1);
        ret.push_back(v0);
        for (int i = 1; i < numRows; ++i) {
            vector<int> v;
            v. push_back(1);
            for ( int j = 1; j < ret[i-1].size(); ++j)
                v.push_back(ret[i-1][j-1]+ret[i-1][j]);
            v.push_back(1);
            ret.push_back(v);
        }
        return ret;
    }
};
