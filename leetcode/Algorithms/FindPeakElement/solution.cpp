// binary-search like solution by hxdone

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low = 0;
        int high = nums.size()-1;
        while (low <= high) {
            int mid = (low+high)/2;
            if (mid == 0 || nums[mid] > nums[mid-1]) {
                if (mid == nums.size()-1 || nums[mid] > nums[mid+1])
                    return mid;
                else
                    low = mid+1;
            } else // nums[mid] < nums[mid-1]
                high = mid-1;
        }
        return 0;
    }
};
