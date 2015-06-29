// by hxdone

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int ret = 0;
        stack<int> operands;
        for(int i = 0; i < tokens.size(); ++i) {
           if (tokens[i] == "+") {
               int op2 = operands.top();
               operands.pop();
               int op1 = operands.top();
               operands.pop();
               operands.push(op1+op2);
           } else if (tokens[i] == "-") {
               int op2 = operands.top();
               operands.pop();
               int op1 = operands.top();
               operands.pop();
               operands.push(op1-op2);
           } else if (tokens[i] == "*") {
               int op2 = operands.top();
               operands.pop();
               int op1 = operands.top();
               operands.pop();
               operands.push(op1*op2);
           } else if (tokens[i] == "/") {
               int op2 = operands.top();
               operands.pop();
               int op1 = operands.top();
               operands.pop();
               operands.push(op1/op2);
           } else {
               operands.push(stoi(tokens[i]));
           }
        }
        ret = operands.empty() ? 0 : operands.top();
        return ret;
    }
};
