// 16ms solution by hxdone

class Solution {
public:
	string convert(string s, int numRows) {
		string ret="";
		int cycle = std::max(2*numRows-2,1);
		int round = s.length()/cycle + 1;
		for (int i = 0; i < numRows ; ++i) {
			int last = -1;
			for (int j = 0; j < round; ++j) {
				int k1 = j*cycle + i;
				if (k1 != last) {
					if (k1 >= s.length())
						break;
					ret.push_back(s[k1]);
					last = k1;
				}
				int k2 = (j+1)*cycle - i;
				if (k2 != last) {
					if (k2 >= s.length()) 
						break;
					ret.push_back(s[k2]);
					last = k2;
				}
			}
		}
		return ret;
	}
};
