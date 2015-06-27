// quick-sort style parition solution
// by hxdone

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int start = 0;
        int end = nums.size()-1;
        int pivot = partition(nums, start, end);
        while (pivot != k-1) {
            if (pivot < k-1)
                start = pivot+1;
            else
                end = pivot-1;
            pivot = partition(nums, start, end);
        }
        return nums[k-1];
    }
private:
    int partition(vector<int>& nums, int start, int end) {
        int j = start;
        for (int i = start+1; i <= end; ++i) {
            if (nums[i] > nums[start]) {
                swap(nums,i,++j);
            }
        }
        swap(nums,start,j);
        return j;
    }
    inline int swap(vector<int>& nums, int i, int j) {
        if (i != j) {
            int tmp = nums[i];
            nums[i] = nums[j];
            nums[j] = tmp;
        }
    }
};
