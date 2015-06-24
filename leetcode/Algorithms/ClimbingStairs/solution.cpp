// Fibonacci sequence essentially
// by hxdone

class Solution {
public:
    int climbStairs(int n) {
        if (n < 0) return 0;
        vector<int> num_ways;
        num_ways.push_back(1);
        num_ways.push_back(1);
        for (int i = 2; i <= n; ++i)
            num_ways.push_back(num_ways[i-1]+num_ways[i-2]);
        return num_ways[n];
    }
};
