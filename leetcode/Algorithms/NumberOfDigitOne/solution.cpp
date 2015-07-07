// by hxdone

class Solution {
public:
    int countDigitOne(int n) {
        int count = 0;
        int lower_number = 0;
        int i = 0;
        int power = 1;
        while (n > 0) {
            if (n%10 > 1)
                count += n/10*power+power;
            else if (n%10 == 1)
                count += n/10*power+(lower_number+1);
            else
                count += n/10*power;
            lower_number += n%10*power;
            n /= 10;
            power *= 10;
        }
        return count;
    }
};
