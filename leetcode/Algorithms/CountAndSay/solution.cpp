// by hxdone

class Solution {
public:
    string countAndSay(int n) {
        string last_str, cur_str;
        if (n < 1) return last_str;
        last_str.push_back('1');
        for (int i = 1; i < n; ++i) {
            cur_str.clear();
            char last_char = last_str[0];
            int count = 1;
            for (int j = 1; j < last_str.length(); ++j) {
                if (last_str[j] == last_char)
                    ++count;
                else {
                    while (count) {
                        cur_str.push_back('0'+count%10);
                        count /= 10;
                    }
                    cur_str.push_back(last_char);
                    last_char = last_str[j];
                    count = 1;
                }
            }
            while (count) {
                cur_str.push_back('0'+count%10);
                count /= 10;
            }
            cur_str.push_back(last_char);
            cur_str.swap(last_str);
        }
        
        return last_str;
    }
};
