// by hxdone

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (int i = 0; i<s.length(); ++i) {
            switch(s[i]) {
                case '(':
                case '[':
                case '{':
                    st.push(s[i]);
                    break;
                case ')':
                    if (st.empty() || st.top() != '(') return false;
                    st.pop();
                    break;
                case ']':
                    if (st.empty() || st.top() != '[') return false;
                    st.pop();
                    break;
                case '}':
                    if (st.empty() || st.top() != '{') return false;
                    st.pop();
                    break;
                default:
                    return false;
            }
        }
        return st.empty();
    }
};
