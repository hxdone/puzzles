// extra stack to store minimum value.
// by hxdone

class MinStack {
public:
    void push(int x) {
        nums.push(x);
        if (min_val.empty())
            min_val.push(x);
        else
            min_val.push(min(x, min_val.top()));
    }

    void pop() {
        nums.pop();
        min_val.pop();
    }

    int top() {
        return nums.top();
    }

    int getMin() {
        return min_val.top();
    }
private:
    stack<int> nums;
    stack<int> min_val;
};
