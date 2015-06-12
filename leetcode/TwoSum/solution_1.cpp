// Solve it with quick sort and binary search.
// author: hxdone

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ret;
        int cnt = nums.size();
        
        // sort nums with idx swapping
        vector<int> sorted_idx;
        for (int i = 0; i < cnt; ++i)
            sorted_idx.push_back(i);
        quick_sort(nums, sorted_idx, 0, cnt-1);
        
        // binary search to check the pairs
        for (int i = 0; i < cnt; ++i) {
            // binary search returns the largest index among elements of the same value 
            int j = binary_search(nums, sorted_idx, target-nums[i]);
            if (j != -1 && i != j) {
                ret.push_back(i+1);
                ret.push_back(j+1);
                return ret;
            }
        }
        return ret;
    }
private:
    void quick_sort(const vector<int>& nums, vector<int>& sorted_idx, int low, int high) {
        if (low >= high)
            return;
        int pivot_idx = partition(nums, sorted_idx, low, high);
        quick_sort(nums, sorted_idx, low, pivot_idx-1);
        quick_sort(nums, sorted_idx, pivot_idx+1, high);
    }
    
    int partition (const vector<int>& nums, vector<int>& sorted_idx, int low, int high) {
        swap(sorted_idx, low, (low+high)/2);
        int i = low;
        for (int j = low+1; j <= high; ++j)
            if (compare(nums, sorted_idx[j], sorted_idx[low]) < 0)
                swap(sorted_idx, ++i, j);
        swap(sorted_idx, low, i);
        return i;
    }
    
    inline int compare(const vector<int>& nums, int i, int j) {
        // compare first by value, then by index
        int ret = nums[i] - nums[j];
        return (ret != 0) ? ret : (i-j);
    }
    
    inline void swap (vector<int>& sorted_idx, int i, int j) {
        if (i != j) {
            int tmp_idx = sorted_idx[i];
            sorted_idx[i] = sorted_idx[j];
            sorted_idx[j] = tmp_idx;
        }
    }
    
    // return the index of the rightmost element equal to value
    int binary_search(vector<int>& nums, vector<int>sorted_idx, int value) {
        int low = 0;
        int high = sorted_idx.size()-1;
        while (low < high) {
            int mid = (low+high+1)/2;
            if (value < nums[sorted_idx[mid]])
                high = mid-1;
            else
                low = mid;
        }
        if (low == high && nums[sorted_idx[low]] == value)
            return sorted_idx[low];
        else
            return -1;
    }
};
