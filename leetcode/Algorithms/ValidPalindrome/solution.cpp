// by hxdone

class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0, j = s.length()-1;
        while (i <= j) {
            if (valid_char(s[i]) == 0) {
                ++i;
                continue;
            }
            if (valid_char(s[j]) == 0) {
                --j;
                continue;
            }
            if (valid_char(s[i]) == valid_char(s[j])) {
                ++i;
                --j;
            } else
                return false;
        }
        return true;
    }
private:
    char valid_char(char c) {
        if (c >= 'A' && c <= 'Z')
            return c-'A'+'a';
        else if ((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9'))
            return c;
        return 0;
    }
};
