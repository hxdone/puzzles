// bitwise operation using 3 extra space 
// by hxdone

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int one_bits = 0, two_bits = 0, three_bits = 0xffffffff;
        for (int i = 0; i < nums.size(); ++i) {
            int t = two_bits;
            two_bits = one_bits&nums[i]|(two_bits&(~nums[i]));
            one_bits = three_bits&nums[i]|(one_bits&(~nums[i]));
            three_bits = t&nums[i]|(three_bits&(~nums[i]));
        }
        return one_bits|two_bits;
    }
};
