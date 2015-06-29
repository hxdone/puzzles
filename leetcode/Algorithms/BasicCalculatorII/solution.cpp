// by hxdone

class Solution {
public:
    int calculate(string s) {
        int digit_start_idx = -1;
        vector<string> tokens;
        for (int i = 0; i < s.length(); ++i) {
            switch (s[i]) {
                case '+':
                case '-':
                case '*':
                case '/':
                case ' ':
                {
                    if (digit_start_idx != -1) {
                        tokens.push_back(s.substr(digit_start_idx, i-digit_start_idx));
                        digit_start_idx = -1;
                    }
                    if (s[i] != ' ')
                        tokens.push_back(s.substr(i,1));
                    break;
                }
                default:
                {
                    if (digit_start_idx == -1)
                        digit_start_idx = i;
                }
            }
        }
        if (digit_start_idx != -1)
            tokens.push_back(s.substr(digit_start_idx, s.length()-digit_start_idx));
        
        stack<long> operands;
        stack<char> operators;
        for (int i = 0; i < tokens.size(); ++i) {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
                while (!operators.empty() && lower_than(tokens[i][0], operators.top())) {
                    char op = operators.top();
                    operators.pop();
                    long num2 = operands.top();
                    operands.pop();
                    long num1 = operands.top();
                    operands.pop();
                    operands.push(calc(num1, num2, op));
                }
                operators.push(tokens[i][0]);
            } else {
                operands.push(stol(tokens[i]));
            }
        }
        while (!operators.empty()) {
            char op = operators.top();
            operators.pop();
            long num2 = operands.top();
            operands.pop();
            long num1 = operands.top();
            operands.pop();
            operands.push(calc(num1, num2, op));
        }
        return operands.top();
    }
private:
    long calc(long num1, long num2, char op) {
        switch (op) {
            case '+': return num1+num2;
            case '-': return num1-num2;
            case '*': return num1*num2;
            case '/': return num1/num2;
            default: return 0;
        }
    }
    bool lower_than(char op_after, char op_before) {
        if (op_after == '+' || op_after == '-')
            return true;
        else {
            if (op_before == '*' || op_before == '/')
                return true;
            return false;
        }
    }
};
