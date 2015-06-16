// by hxdone

class Stack {
public:
    Stack() {
        p_qa = new queue<int>;
        p_qb = new queue<int>;
    }
    
    ~Stack() {
        delete p_qa;
        delete p_qb;
    }
    
    // Push element x onto stack.
    void push(int x) {
        p_qa->push(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        int x = p_qa->front();
        p_qa->pop();
        while (!p_qa->empty()) {
            p_qb->push(x);
            x = p_qa->front();
            p_qa->pop();
        }
        auto tmp = p_qa;
        p_qa = p_qb;
        p_qb = tmp;
    }

    // Get the top element.
    int top() {
        int x;
        while (!p_qa->empty()) {
            x = p_qa->front();
            p_qa->pop();
            p_qb->push(x);
        }
        auto tmp = p_qa;
        p_qa = p_qb;
        p_qb = tmp;
        return x;
    }

    // Return whether the stack is empty.
    bool empty() {
        return p_qa->empty();
    }
    
private:
    queue<int>* p_qa;
    queue<int>* p_qb;
};
