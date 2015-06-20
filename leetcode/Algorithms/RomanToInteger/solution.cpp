// stack solution by hxdone

class Solution {
public:
	int romanToInt(string s) {
		map<char, int> sym_table;
		sym_table['I'] = 1;
		sym_table['V'] = 5;
		sym_table['X'] = 10;
		sym_table['L'] = 50;
		sym_table['C'] = 100;
		sym_table['D'] = 500;
		sym_table['M'] = 1000;
		stack<int> v_stack;
		for (int i = 0; i < s.length(); ++i) {
			int v = sym_table[s[i]];
			while (!v_stack.empty() && v > v_stack.top()) {
				v = v-v_stack.top();
				v_stack.pop();
			}
			v_stack.push(v);
		}
		int ret = 0;
		while (!v_stack.empty()) {
			ret += v_stack.top();
			v_stack.pop();
		}
		return ret;
	}
}; 
