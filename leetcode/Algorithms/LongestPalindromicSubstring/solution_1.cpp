// naive solution by hxdone

class Solution {
public:
    string longestPalindrome(string s) {
        string ret;
        for(int i = 0; i < s.length(); ++i) {
            int j;
            for (j = 0; i-j >= 0 && i+j < s.length() && s[i-j] == s[i+j]; ++j);
            if (2*j-1 > ret.length())
                ret = s.substr(i-j+1, 2*j-1);
            for (j = 0; i-j >= 0 && i+1+j < s.length() && s[i-j] == s[i+1+j]; ++j);
            if (2*j > ret.length())
                ret = s.substr(i-j+1, 2*j);
        }
        return ret;
    }
};
