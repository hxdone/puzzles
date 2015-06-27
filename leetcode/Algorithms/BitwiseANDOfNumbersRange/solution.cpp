// three-line solution by hxdone

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int k;
        for (k = 0; k < 31 && n-m > 1<<k; ++k);
        return (m&n)>>k<<k;
    }
};
