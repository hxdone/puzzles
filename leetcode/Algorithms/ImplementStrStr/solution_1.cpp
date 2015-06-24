// KMP solution by hxdone

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.length() == 0)
            return 0;
        vector<int> next_pos;
        int i = -1, j = 0;
        int m = needle.length();
        int n = haystack.length();
        next_pos.push_back(-1);
        while (j < m-1) {
            if (i == -1 || needle[i] == needle[j]) {
                next_pos.push_back(++i);
                ++j;
            } else
                i = next_pos[i];
        }
        
        i = 0;
        j = 0;
        while (i < m && j < n) {
            if (i == -1 || haystack[j] == needle[i]) {
                ++i;
                ++j;
            } else
                i = next_pos[i];
        }
        return (i == m)? (j-i):-1;
    }
};
