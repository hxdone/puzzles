// by hxdone

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0)
            return 0;
        int lowest = prices[0];
        int max_profit = 0;
        for (int i = 1; i < prices.size(); ++i) {
            max_profit = max(prices[i]-lowest, max_profit);
            lowest = min(lowest, prices[i]);
        }
        return max_profit;
    }
};
