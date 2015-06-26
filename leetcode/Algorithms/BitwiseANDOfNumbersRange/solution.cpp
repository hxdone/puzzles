// by hxdone

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int ret = m&n;
        int dist = n-m;
        for (int k = 0; k <= 31 && dist-1 >= 1<<k; ++k)
            ret &= ~(1<<k);
        return ret;
    }
};
