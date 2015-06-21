// by hxdone

class Solution {
public:
	string convertToTitle(int n) {
		string s = "";
		while (n) {
			char c = (n-1)%26+'A';
			s.push_back(c);
			n = (n-1)/26;
		}
		for (int i = 0; i < (s.length()+1)/2; ++i) {
			char tmp = s[i];
			s[i] = s[s.length()-1-i];
			s[s.length()-1-i] = tmp;
		}
		return s;
	}
};
