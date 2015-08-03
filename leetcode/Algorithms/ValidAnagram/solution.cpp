// by hxdone

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length())
            return false;
        int counter_s[26] = {0};
        int counter_t[26] = {0};
        int i = 0;
        while (i < s.length()) {
            ++counter_s[s[i]-'a'];
            ++counter_t[t[i]-'a'];
            ++i;
        }
        for (i = 0; i < 26; ++i)
            if (counter_s[i] != counter_t[i])
                return false;
        return true;
    }
};
