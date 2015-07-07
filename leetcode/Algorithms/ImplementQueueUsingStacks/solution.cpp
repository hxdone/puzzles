// by hxdone

class Queue {
public:
    // Push element x to the back of queue.
    void push(int x) {
        in_stack.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        if (out_stack.empty()) {
            while (!in_stack.empty()) {
                out_stack.push(in_stack.top());
                in_stack.pop();
            }
        }
        out_stack.pop();
    }

    // Get the front element.
    int peek(void) {
        if (out_stack.empty()) {
            while (!in_stack.empty()) {
                out_stack.push(in_stack.top());
                in_stack.pop();
            }
        }
        return out_stack.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return in_stack.empty() && out_stack.empty();
    }
    stack<int> in_stack;
    stack<int> out_stack;
};
