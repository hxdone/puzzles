// by hxdone

class Solution {
public:
    int lengthOfLastWord(string s) {
        int cnt = 0;
        for (int i = s.length()-1; i >= 0; --i) {
            if (cnt == 0 && s[i] == ' ')
                continue;
            else if(s[i] != ' ')
                ++cnt;
            else return cnt;
        }
        return cnt;
    }
};
