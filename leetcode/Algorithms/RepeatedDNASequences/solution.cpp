// by hxdone
// TODO: the performance is not satisfying, yet to optimize.

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ret;
        unordered_map<int,int> seq_map;
        int seq = 0;
        for (int i = 0; i < min((int)s.length(),10); ++i) {
            switch (s[i]) {
                case 'A': { seq <<= 2; break; }
                case 'T': { seq = (seq<<2)+1; break; }
                case 'C': { seq = (seq<<2)+2; break; }
                case 'G': { seq = (seq<<2)+3; break; }
            }
        }
        ++seq_map[seq];
        for (int i = 10; i < s.length(); ++i) {
            seq &= 0x3ffff;
            switch (s[i]) {
                case 'A': { seq <<= 2; break; }
                case 'T': { seq = (seq<<2)+1; break; }
                case 'C': { seq = (seq<<2)+2; break; }
                case 'G': { seq = (seq<<2)+3; break; }
            }
            if (++seq_map[seq] == 2) {
                string t;
                for(int i = 0; i < 10; ++i) {
                    int j = (seq>>(18-i-i)) & 0x3;
                    switch (j) {
                        case 0: { t.push_back('A'); break; }
                        case 1: { t.push_back('T'); break; }
                        case 2: { t.push_back('C'); break; }
                        case 3: { t.push_back('G'); break; }
                    }
                }
                ret.push_back(t);
            }
        }
        return ret;
    }
};
