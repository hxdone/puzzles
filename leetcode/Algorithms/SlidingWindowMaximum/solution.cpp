// max-heap with index, by hxdone

struct HeapElement {
  int val;
  int idx;
};

class MaxHeap {
public:
    void push(HeapElement e) {
        elems.push_back(e);
        int i = elems.size()-1;
        while (parent(i) >= 0) {
            int parent_i = parent(i);
            if (elems[i].val > elems[parent_i].val) {
                HeapElement tmp = elems[parent_i];
                elems[parent_i] = elems[i];
                elems[i] = tmp;
                i = parent_i;
            } else
                return;
        }
    }
    
    inline void pop() {
        if (elems.size() > 0) {
            elems[0] = elems[elems.size()-1];
            elems.pop_back();
            heapify(0);
        }
    }
    
    inline HeapElement top() {
        return elems[0];
    }
    
    void heapify(int i) {
        while (i < elems.size()) {
            int max_i = i;
            int left_i = left(i);
            int right_i = right(i);
            if (left_i < elems.size()) {
                if (elems[left_i].val > elems[i].val)
                    max_i = left_i;
                if (right_i < elems.size() && elems[right_i].val > elems[max_i].val)
                    max_i = right_i;
            }
            if (max_i != i) {
                HeapElement tmp = elems[max_i];
                elems[max_i] = elems[i];
                elems[i] = tmp;
                i = max_i;
            } else
                return;
        }
    }
    
    inline int parent(int idx) {
        return (idx-1)/2;
    }
    
    inline int left(int idx) {
       return 2*idx+1; 
    }
    
    inline int right(int idx) {
        return 2*idx+2;
    }
    
private:
    vector<HeapElement> elems;
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ret;
        if (nums.size() < k)
            return ret;
        
        MaxHeap max_heap;
        for (int i = 0; i < min(k-1, (int)(nums.size())-1); ++i) {
            HeapElement e;
            e.val = nums[i];
            e.idx = i;
            max_heap.push(e);
        }
        for (int i = k-1; i < nums.size(); ++i) {
            HeapElement e;
            e.val = nums[i];
            e.idx = i;
            max_heap.push(e);
            while (max_heap.top().idx < i-k+1)
                max_heap.pop();
            ret.push_back(max_heap.top().val);
        }
        return ret;
    }
};
