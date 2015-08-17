// divide and conquer solution by hxdone

class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> numbers;
        vector<char> operators;
        int cur_num_val = 0;
        for (int i = 0; i < input.length(); ++i) {
            if (input[i] >= '0' && input[i] <= '9') {
                cur_num_val = cur_num_val*10+(input[i]-'0');
            } else {
                numbers.push_back(cur_num_val);
                cur_num_val = 0;
                operators.push_back(input[i]);
            }
        }
        numbers.push_back(cur_num_val);
        vector<int> ret;
        expr(numbers, operators, 0, operators.size(), ret);
        return ret;
    }
    
    void expr(const vector<int>& numbers, const vector<char>& operators, int operator_start_idx, int operator_num, vector<int>& ret) {
        if (operator_num == 0) {
            ret.push_back(numbers[operator_start_idx]);
        } else if (operator_num > 0) {
            vector<int> left, right;
            for (int i = 0; i < operator_num; ++i) {
                left.clear();
                right.clear();
                expr(numbers, operators, operator_start_idx, i, left);
                expr(numbers, operators, operator_start_idx+i+1, operator_num-i-1, right);
                for (int j = 0; j < left.size(); ++j)
                    for (int k = 0; k < right.size(); ++k) {
                        switch(operators[operator_start_idx+i]) {
                            case '+':   { ret.push_back(left[j] + right[k]); break;}
                            case '-':   { ret.push_back(left[j] - right[k]); break;}
                            case '*':   { ret.push_back(left[j] * right[k]); break;}
                            default:    {break;}
                        }
                    }
            } 
        }
    }
};
