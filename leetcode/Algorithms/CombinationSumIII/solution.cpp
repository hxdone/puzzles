// backtracking-based solution by hxdone

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int> > ret;
        vector<int> cur;
        int remain = n;
        int i = 0;
        while (i != -1) {
            if (i == k-1) {
                if ((i == 0 || remain > cur[i-1]) && remain <= 9) {
                    cur.push_back(remain);
                    ret.push_back(cur);
                    cur.pop_back();
                }
                --i;
            } else if (i == cur.size()) {
                int last_elem = (i>0) ? cur[i-1]:0;
                if ((k-i)*last_elem+(k-i)*(k-i+1)/2 > remain || last_elem+k-i > 9) {
                    --i;
                } else {
                    cur.push_back(last_elem+1);
                    remain -= cur[i];
                    ++i;
                }
            } else if (i == cur.size()-1) {
                if ((k-i)*cur[i]+(k-i)*(k-i+1)/2 > remain+cur[i] || cur[i]+k-i > 9) {
                    remain += cur[i];
                    cur.pop_back();
                    --i;
                } else {
                    cur[i] += 1;
                    remain -= 1;
                    ++i;
                }
            }
        }
        return ret;
    }
};
