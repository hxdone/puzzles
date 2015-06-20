// solution by hxdone

class Solution {
public:
	int myAtoi(string str) {
		int i = 0;
		for(; i < str.size() && str[i] == ' '; ++i);
		if (i == str.size())
			return 0;
		char sign = str[i];
		if (sign == '-' || sign == '+')
			++i;
		int val = 0;
		while (i < str.size()) {
			if (str[i] >= '0' && str[i] <= '9') {
				int digit = str[i]-'0';
				if (sign == '-' && val > (INT_MIN+digit)/(-10)) // check out of range
					return INT_MIN;
				else if (sign != '-' && val > (INT_MAX-digit)/10) // check out of range
					return INT_MAX;
				else
					val = val*10 + digit;
			} else
				return (sign=='-') ? -val:val;
			++i;
		}
		return (sign=='-') ? -val:val;
	}
};
