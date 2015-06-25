// binary-search solution by hxdone

class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size()-1;
        while (nums[low] > nums[high]) {
            int mid = (low+high)/2;
            if (nums[mid] >= nums[low])
                low = mid+1;
            else
                high = mid;
        }
        return nums[low];
    }
};
