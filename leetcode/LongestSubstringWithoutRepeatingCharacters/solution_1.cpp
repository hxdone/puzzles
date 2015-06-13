// 12ms DP solution by hxdone
// O(n) time complexity and O(1) space complexity.

#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int idx_map[256]; // character -> last index
		for (int i = 0; i < 256; ++i)
			idx_map[i] = -1;
		int max_len = 0;
		int cur_start_idx = 0;
		int len = s.length();
		for (int i = 0; i < len; ++i) {
			char c = s[i];
			if (idx_map[c] != -1 && idx_map[c] >= cur_start_idx) {
				max_len = std::max(i-cur_start_idx, max_len);
				cur_start_idx = idx_map[c]+1;
			}
			idx_map[c] = i;
		}
		max_len = std::max(len-cur_start_idx, max_len);
		return max_len;
	}

};

int main()
{
	string s("abdcdaefghi");
	cout << s << endl;
	cout << Solution().lengthOfLongestSubstring(s) << endl;
	return 0;
}
