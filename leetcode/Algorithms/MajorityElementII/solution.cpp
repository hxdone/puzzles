// by hxdone

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        if (nums.size() == 0)
            return nums;
        
        int a = nums[0];
        int b;
        int cnt_a = 1;
        int cnt_b = 0;
        int count_a = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (cnt_a > 0 && cnt_b > 0) {
                if (nums[i] == a)
                    ++cnt_a;
                else if (nums[i] == b)
                    ++cnt_b;
                else {
                    --cnt_a;
                    --cnt_b;
                }
            } else if (cnt_a > 0) {
                if (nums[i] == a)
                    ++cnt_a;
                else {
                    b = nums[i];
                    cnt_b = 1;
                }
            } else if (cnt_b > 0) {
                if (nums[i] == b)
                    ++cnt_b;
                else {
                    a = nums[i];
                    cnt_a = 1;
                }
            } else {
                a = nums[i];
                cnt_a = 1;
            }
        }
        vector<int> ret;
        //check majority
        if (cnt_a > 0) {
            cnt_a = 0;
            for (int i = 0; i < nums.size(); ++i) {
                if (nums[i] == a)
                    ++cnt_a;
                if (cnt_a > nums.size()/3) {
                    ret.push_back(a);
                    break;
                }
            }
        }
        if (cnt_b > 0) {
            cnt_b = 0;
            for (int i = 0; i < nums.size(); ++i) {
                if (nums[i] == b)
                    ++cnt_b;
                if (cnt_b > nums.size()/3) {
                    ret.push_back(b);
                    break;
                }
            }
        }
        return ret;
    }
};
