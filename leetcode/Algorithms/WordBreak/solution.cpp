// DP solution by hxdone

class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        if(s.length() == 0)
            return true;
        vector<bool> memento;
        for (int i = 0; i < s.length(); ++i)
            memento.push_back(false);
        memento.push_back(true);
        for (int i = s.length()-1; i >= 0; --i)
            for (int len = 1; len <= s.length()-i; ++len)
                if (wordDict.find(s.substr(i,len)) != wordDict.end() && memento[i+len])
                    memento[i] = true;
        return memento[0];
    }
};
