// by hxdone

class Solution {
public:
    bool isNumber(string s) {
        // skip leading spaces
        int i = 0;
        for (; i < s.length() && s[i] == ' '; ++i);
        if (i == s.length())
            return false;
        bool digit_starts = false;
        bool before_e = true;
        bool before_dot = true;
        for (; i < s.length(); ++i) {
            if (s[i] == '.') {
                if (!before_dot || !before_e)
                    return false;
                before_dot = false;
                //digit_starts = true;
            } else if (s[i] == 'e' || s[i] == 'E') {
                if (!digit_starts || !before_e)
                    return false;
                before_e = false;
                before_dot = true;
                digit_starts = false;
            } else if (s[i] == '+' || s[i] == '-') {
                if (digit_starts || !before_dot)
                    return false;
            } else if (s[i] >= '0' && s[i] <= '9') {
                digit_starts = true;
            } else if (s[i] == ' ') {
                if (!digit_starts)
                    return false;
                for (; i < s.length() && s[i] == ' '; ++i);
                return i >= s.length();
            } else
                return false;
        }
        return digit_starts;
    }
};
