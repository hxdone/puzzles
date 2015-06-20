// compare half the digits to avoid overflow.
// by hxdone

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        int digit_cnt = 0;
        int tmp = x;
        do {
            tmp /= 10;
            ++digit_cnt;
        } while(tmp);
        int mid = (digit_cnt+1)/2;
        
        int y = 0;
        for (int i = 0; i < mid-1; ++i) {
            y = y*10 + x%10;
            x /= 10;
        }
        y = y*10 + x%10;
        if (digit_cnt%2 == 0)
            x /= 10; 

        return x == y;
    }
};

