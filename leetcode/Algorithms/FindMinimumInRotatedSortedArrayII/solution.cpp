// by hxdone

class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size()-1;
        while (low < high) {
            if (nums[low] < nums[high])
                return nums[low];
            else if (nums[low] > nums[high]) {
                int mid = (low+high)/2;
                if (nums[mid] <= nums[high])
                    high = mid;
                else
                    low = mid+1;
            } else {
                // worst case here is O(n) even if you do it with binary search
                while (low < high && nums[low] == nums[high])
                    ++low;
            }
        }
        if (low == high)
            return nums[low];
    }
};
