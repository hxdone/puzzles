// by hxdone

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ret;
        int i = digits.size()-1;
        while (i >= 0 && digits[i]+1 == 10) {
            ret.push_back(0);
            --i;
        }
        if (i >= 0) {
            ret.push_back(digits[i--]+1);
            for (;i >= 0; --i)
                ret.push_back(digits[i]);
        } else
            ret.push_back(1);
        for (int i = 0; i < ret.size()/2; ++i) {
            int tmp = ret[i];
            ret[i] = ret[ret.size()-1-i];
            ret[ret.size()-1-i] = tmp;
        }
        return ret;
    }
};
