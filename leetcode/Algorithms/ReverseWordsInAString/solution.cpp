// by hxdone

class Solution {
public:
    void reverseWords(string &s) {
        int start = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == ' ') {
                reverseStr(s, start, i-1);
                start = i+1;
            }
        }
        reverseStr(s,start,s.length()-1);
        reverseStr(s,0,s.length()-1);
        int j = 0;
        for(int i = 0; i < s.length(); ++i) {
            if (s[i] != ' ')
                s[j++] = s[i];
            else if (j != 0 && i < s.length()-1 && s[i+1] != ' ')
                s[j++] = ' ';
        }
        s = s.substr(0,j);
    }
    
private:
    void reverseStr(string& s, int start, int end) {
        if (start >= end)
            return;
        for (int i = start; i < (start+end+1)/2; ++i) {
            char c = s[i];
            s[i] = s[end+start-i];
            s[end+start-i] = c;
        }
    }
};
