// 8ms solution check integer range with reversing calculation from boundary.
// by hxdone.

class Solution {
public:
    int myAtoi(string str) {
        int i = 0;
        for(; i < str.size() && str[i] == ' '; ++i);
        if (i == str.size())
            return 0;
        bool minus = (str[i] == '-');
        if (str[i] == '-' || str[i] == '+')
            ++i;
        int val = 0;
        for (;i < str.size() && str[i] >= '0' && str[i] <= '9'; ++i) {
            int digit =  minus ? ('0'-str[i]) : (str[i]-'0');
            if (minus && val < (INT_MIN-digit)/10)
                return INT_MIN;
            else if (!minus && val > (INT_MAX-digit)/10)
                return INT_MAX;
            else
                val = val*10 + digit;
        }
        return val;
    }
};

