// solve with a bool array
// by hxdone

class Solution {
public:
    int countPrimes(int n) {
        if (n < 2) return 0;
        bool* np = new bool[n-1]; //not_prime
        for (int i = 0; i < n-1; ++i)
            np[i] = false;
        int numPrimes = n-2; // kickout integer 1
        for (int i = 2; i*i <= n-1; ++i) {
            if (np[i]) continue;
            int max_fold = (n-1)/i;
            for (int j = std::max(2,i); j <= max_fold; ++j) {
                int k = i*j;
                if (!np[k]) {
                    --numPrimes;
                    np[k]=true;
                }
            }
        }
        return numPrimes;
    }
};

