// DP solution with memento
// by hxdone

class Solution {
public:
    bool isMatch(string s, string p) {
        // 1. treat regular expression into tokens
        vector<pair<char, bool> > tokens; // character, is_asterisk_character
        for(int i = 1; i < p.length(); ++i) {
            if (p[i] == '*') {
                tokens.push_back(pair<char,bool>(p[i-1],true));
            } else if (p[i-1] != '*'){
                tokens.push_back(pair<char,bool>(p[i-1],false));
            }
        }
        if (p.length() > 0 && p[p.length()-1] != '*')
            tokens.push_back(pair<char, bool>(p[p.length()-1], false));

        // 2. initialize memento for dynamic programming
        vector<vector<char>> result; // memento
        for (int i = 0; i <= s.length(); ++i) {
            result.push_back(vector<char>());
            for (int j = 0; j <= tokens.size(); ++j)
                result[i].push_back(-1);
        }

        // 3. do the calculation
        return isMatch(s, 0, tokens, 0, result);
    }
private:
    inline bool isMatch(char s, char p) {
        return (p == '.' || s == p);
    }
    
    bool isMatch(string& s, int idx_s, vector<pair<char, bool>>& tokens, int idx_t, vector<vector<char>>& result) {
        if (result[idx_s][idx_t] != -1)
            return result[idx_s][idx_t] == 1;
        else if (idx_s == s.length()) {
            for (int j = idx_t; j < tokens.size(); ++j)
                if (!tokens[j].second) {
                    result[idx_s][idx_t] = 0;
                    return false;
                }
            result[idx_s][idx_t] = 1;
            return true;
        } else {
            if (idx_t == tokens.size()) {
                result[idx_s][idx_t] = 0;
                return false;
            } else if (!tokens[idx_t].second) {
                bool ret = isMatch(s[idx_s], tokens[idx_t].first) && isMatch(s, idx_s+1, tokens, idx_t+1, result);
                result[idx_s][idx_t] = ret? 1:0;
                return ret;
            } else {
                bool ret = (isMatch(s[idx_s], tokens[idx_t].first) && isMatch(s, idx_s+1, tokens, idx_t, result)) ||
                    isMatch(s, idx_s, tokens, idx_t+1, result);
                result[idx_s][idx_t] = ret? 1:0;
                return ret;
            }
        }
    }
};
