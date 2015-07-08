// double binary search solution by hxdone

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ret;
        ret.push_back(lower_bound(nums, target));
        ret.push_back(upper_bound(nums, target));
        return ret;
    }
    
private:
    int lower_bound(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size()-1;
        while (low < high) {
            int mid = (low+high)/2;
            if (nums[mid] > target)
                high = mid-1;
            else if (nums[mid] < target)
                low = mid+1;
            else
                high = mid;
        }
        return (low == high && nums[low] == target)? low: -1;
    }
    int upper_bound(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size()-1;
        while (low < high) {
            int mid = (low+high+1)/2;
            if (nums[mid] > target)
                high = mid-1;
            else if (nums[mid] < target)
                low = mid+1;
            else
                low = mid;
        }
        return (low == high && nums[low] == target)? low: -1;
    }
};
