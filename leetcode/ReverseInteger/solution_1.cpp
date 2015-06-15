// Use "int64" to deal with "int" overflow issue.
// by hxone

#include <cmath>
#include <iostream>
using namespace std;

//typedef long long int64;
typedef long int64;


class Solution {
public:
    int reverse(int x) {
        if (x == 0x80000000)
            return 0;
        bool sign = (x >= 0); 
        int64 val = 0;
        x = sign?x:-x;
        while (x > 0) {
            val = val*10 + x%10; 
            x = x/10; 
        }
        val = sign?val:-val;
        if (val > 0x7fffffffL || val < (int)0x80000000)
            return 0;
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
