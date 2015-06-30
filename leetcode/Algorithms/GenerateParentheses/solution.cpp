// backtracking-based solution by hxdone

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        string s;
        int i = 0;
        int left = 0;
        while (i != -1) {
            if (i == 2*n) {
                ret.push_back(s);
                --i;
            } else if (i == s.length()) { // append more
                if (left < n) {
                    ++left;
                    s.push_back('(');
                } else
                    s.push_back(')');
                ++i;
            } else if (i == s.length()-1) { // backtracking
                if (s[i] == '(' && left-1 >= (i+2)/2) {
                    s[i] = ')';
                    --left;
                    ++i;
                } else {
                    if (s[i] == '(')
                        --left;
                    s.pop_back();
                    --i;
                }
            } 
        }
        return ret;
    }
};
