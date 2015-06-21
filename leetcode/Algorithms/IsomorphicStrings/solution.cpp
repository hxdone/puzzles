// by hxdone

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        char s2t[256] = {0};
        char t2s[256] = {0};
        for (int i = 0; i < s.length(); ++i) {
            if (s2t[s[i]] == 0 && t2s[t[i]] == 0) {
                s2t[s[i]] = t[i];
                t2s[t[i]] = s[i];
            } else if (s2t[s[i]] != t[i] || t2s[t[i]] != s[i])
                return false;
        }
        return true;
    }
};
