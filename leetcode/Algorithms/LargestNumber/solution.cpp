// by hxdone

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// return true only if s1s2 > s2s1
bool str_compare (string s1, string s2) {
    int total_len = s1.length() + s2.length();
    for (int i = 0; i < total_len; ++i) {
        char c1 = i < s1.length() ? s1[i]:s2[i-(int)s1.length()];
        char c2 = i < s2.length() ? s2[i]:s1[i-(int)s2.length()];
        if (c1 == c2)
            continue;
        else 
            return c1 > c2;
    }
    return false;
}

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> str_of_nums;
        for (int i = 0; i < (int)nums.size(); ++i) {
            string s;
            int num = nums[i];
            while (num > 0) {
                s.push_back('0'+num%10);
                num /= 10;
            }
            if (s.length() == 0)
                s.push_back('0');
            for (int j = 0; j < (int)s.length()/2; ++j) {
                char c = s[j];
                s[j] = s[s.length()-1-j];
                s[s.length()-1-j] = c;
            }
            str_of_nums.push_back(s);
        }
        sort(str_of_nums.begin(), str_of_nums.end(), str_compare);

        string ret;
        for (int i = 0; i < str_of_nums.size(); ++i)
            ret.append(str_of_nums[i]);
        if (ret.length() == 0 || ret[0] == '0')
            return string("0");
        return ret;
    }
private:
};

int main() {
    Solution s;
    vector<int> nums;
    for (int i = 0; i < 20; ++i)
        nums.push_back(0);
    nums.push_back(121);
    nums.push_back(12);
    nums.push_back(0);
    nums.push_back(1);
    cout <<s.largestNumber(nums)<<endl;
}
