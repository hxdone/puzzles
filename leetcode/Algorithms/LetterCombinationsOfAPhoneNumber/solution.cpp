// by hxdone

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ret;
        if (digits.empty())
            return ret;
        vector<string> mapping = {" ","", "abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        string digits_without_one;
        for (int i = 0; i < digits.length(); ++i)
            if (digits[i] != '1')
                digits_without_one.push_back(digits[i]);
        int i = 0;
        string s;
        while (i != -1) {
            if (i == digits_without_one.length()) {
                ret.push_back(s);
                --i;
            } else{
                int d = digits_without_one[i]-'0';
                if (i == s.length()) {
                    s.push_back(mapping[d][0]);
                    ++i;
                } else { // i == s.length()-1
                    int j = 0;
                    while (j < mapping[d].length() && mapping[d][j] != s[i])
                        ++j;
                    if (j == mapping[d].length()-1) {
                        s.pop_back();
                        --i;
                    } else {
                        s[i] = mapping[d][j+1];
                        ++i;
                    }
                }
            }
        }
        return ret;
    }
};
