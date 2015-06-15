// Reversing calculation and comparison to check overflow.
// 8ms solution by hxone

#include <cmath>
#include <iostream>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        if (x == 0x80000000)
            return 0;
        bool sign = (x >= 0); 
        int val = 0;
        x = sign?x:-x;
        while (x > 0) {
            if ((0x7fffffff-x%10)/10 < val)
                return 0; 
            val = val*10 + x%10;
            x = x/10; 
        }
        val = sign?val:-val;
        return val;
    }
};

int main() {
    int x = 1;
    cout << x << " => " << Solution().reverse(x) << endl;
    x = 0;
    cout << x << " => " << Solution().reverse(x) << endl;
    x = 0x80000000;
    cout << x << " => " << Solution().reverse(x) << endl;
    x = 0x80000000+1100000336;
    cout << x << " => " << Solution().reverse(x) << endl;
    x = 0x80000000+1100000326;
    cout << x << " => " << Solution().reverse(x) << endl;
    x = 0x7fffffff;
    cout << x << " => " << Solution().reverse(x) << endl;
    x = 123;
    cout << x << " => " << Solution().reverse(x) << endl;
    x = -321;
    cout << x << " => " << Solution().reverse(x) << endl;
    return 0;
}
