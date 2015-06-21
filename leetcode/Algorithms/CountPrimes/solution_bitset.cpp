// bitset solution.
// by hxdone

#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

class MyBitset {
public:
    MyBitset(unsigned int size) {
        m_size = size;
        p_mem = new char[size/8+1];
        memset(p_mem, 0, size/8+1);
    }
    
    ~MyBitset() {
        delete [] p_mem;
    }
    
    bool test(unsigned int i) {
        if (i > m_size) return false;
        unsigned int byte_idx = i>>3;
        unsigned int byte_off = i-(byte_idx<<3);
        return p_mem[byte_idx] & (1<<byte_off);
    }
    
    void set(unsigned int i) {
        if (i > m_size) return;
        unsigned int byte_idx = i>>3;
        unsigned int byte_off = i-(byte_idx<<3);
        p_mem[byte_idx] |= (1<<byte_off);
    }
    
    void unset(unsigned int i) {
        if (i > m_size) return;
        unsigned int byte_idx = i>>3;
        unsigned int byte_off = i-(byte_idx<<3);
        p_mem[byte_idx] &= ~(1<<byte_off);
    }
    
private:
    unsigned int m_size;
    char* p_mem;
};

class Solution {
public:
    int countPrimes(int n) {
        if (n < 2) return 0;
        MyBitset np(n-1); //not_prime
        int numPrimes = n-2; // kickout integer 1
        for (int i = 2; i*i <= n-1; ++i) {
			if (np.test(i)) continue;
            int max_fold = (n-1)/i;
            for (int j = max(2,i); j <= max_fold; ++j) {
                int k = i*j;
                if (!np.test(k)) {
                    --numPrimes;
                    np.set(k);
                }
            }
        }
        return numPrimes;
    }
};

int main() {
	Solution s;
	int n = 5;
	cout << "n=" << n <<", numPrimes=" << s.countPrimes(5) <<endl;
	cout << sizeof(bool) << endl;
	return 0;
}
