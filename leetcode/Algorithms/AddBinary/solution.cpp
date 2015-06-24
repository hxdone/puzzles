// by hxdone

class Solution {
public:
    string addBinary(string a, string b) {
        string ret;
        int i = a.length()-1;
        int j = b.length()-1;
        char extra = 0; 
        while (i >= 0  || j >= 0) {
            char va = (i < 0 || a[i]=='0') ? 0:1;
            char vb = (j < 0 || b[j]=='0') ? 0:1;
            ret.push_back(((va+vb+extra)%2)?'1':'0');
            extra = (va+vb+extra)>1?1:0;
            --j;
            --i;
        }
        if (extra == 1) ret.push_back('1');
        for (int k = 0; k < ret.size()/2; ++k) {
            char tmp = ret[k];
            ret[k] = ret[ret.size()-1-k];
            ret[ret.size()-1-k] = tmp;
        }
        return ret;
    }
};
