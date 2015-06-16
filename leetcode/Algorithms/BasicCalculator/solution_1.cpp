// solve with reverse polish notation.
// by hxdone

class Solution {
public:
    int calculate(string s) {
        vector<pair<int,bool> > tokens; // <value, is_number>
        tokens = tokenize(s);
        stack<int> operands;
        stack<char> operators;
        for (int i = 0; i < tokens.size(); ++i) {
            if (tokens[i].second) // number
            {
                operands.push(tokens[i].first);
                continue;
            }
            switch(tokens[i].first) {
                case '(':
                    {
                        operators.push('(');
                        break;
                    }
                case ')':
                    {
                        while (!operators.empty()) {
                            auto op = operators.top();
                            if (op == '(') {
                                operators.pop();
                                break;
                            }
                            else if (op == '+' || op == '-') {
                                int x2 = operands.top();
                                operands.pop();
                                int x1 = operands.top();
                                operands.pop();
                                operands.push(op=='+' ? x1+x2 : x1-x2);
                                operators.pop();
                            }
                        }
                        break;
                    }
                case '+':
                    {
                        if(!operators.empty()) {
                            auto op = operators.top();
                            if (op == '+' || op == '-') {
                                int x2 = operands.top();
                                operands.pop();
                                int x1 = operands.top();
                                operands.pop();
                                operands.push(op=='+' ? x1+x2 : x1-x2);
                                operators.pop();
                            }
                        }
                        operators.push('+');
                        break;
                    }
                case '-':
                    {
                        if(!operators.empty()) {
                            auto op = operators.top();
                            if (op == '+' || op == '-') {
                                int x2 = operands.top();
                                operands.pop();
                                int x1 = operands.top();
                                operands.pop();
                                operands.push(op=='+' ? x1+x2 : x1-x2);
                                operators.pop();
                                
                            }
                        }
                        operators.push('-');
                        break;
                    }
            }
        }
        if (!operators.empty()) {
            auto op = operators.top();
            if (op == '+' || op == '-') {
                int x2 = operands.top();
                operands.pop();
                int x1 = operands.top();
                operands.pop();
                operands.push(op=='+' ? x1+x2 : x1-x2);
                operators.pop();
            }
        }
        return operands.top();
    }
private:
    vector<pair<int, bool> > tokenize(string s) {
        vector<pair<int, bool> > ret;
        int val = -1;
        for (int i = 0; i < s.length(); ++i){
            if (s[i] >= '0' && s[i] <= '9') {
                if (val == -1)
                    val = 0;
                val = val*10 + s[i] - '0';
            }
            else {
                if(val != -1) {
                    ret.push_back(pair<int, bool>(val,true));
                    val = -1;
                }
                if (s[i] != ' ')
                    ret.push_back(pair<int, bool>(s[i],false));
            }
        }
        if (val != -1)
            ret.push_back(pair<int, bool>(val,true));
        return ret;
    }
};
