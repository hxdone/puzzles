// char-array hashmap and backward-summing solution by hxdone

class Solution {
public:
    Solution() {
        sym_table['I'] = 1;
        sym_table['V'] = 5;
        sym_table['X'] = 10;
        sym_table['L'] = 50;
        sym_table['C'] = 100;
        sym_table['D'] = 500;
        sym_table['M'] = 1000;
    }
    int romanToInt(string s) {
        int ret = 0;
        int last = 0;
        for (int i = s.length()-1; i >= 0; --i) {
            int v = sym_table[s[i]];
            if (v >= last) {
                ret += v;
                last = v;
            }
            else
                ret -= v;
        }
        return ret;
    }
private:
    int sym_table[256];
};
