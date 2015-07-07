// by hxdone

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        bool bought = false;
        int profit = 0;
        int buy_price = 0;
        for  (int i = 0; i < (int)prices.size()-1; ++i) {
            if (!bought && prices[i] < prices[i+1]) {
                bought = true;
                buy_price = prices[i];
            }  else if (bought && prices[i] > prices[i+1]) {
                bought = false;
                profit += (prices[i]-buy_price);
            }
        }
        if (bought)
            profit += (prices[(int)prices.size()-1]-buy_price);
        return profit;
    }
};
