class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int buyAt = prices[0];
        int profit = 0;

        for (int i = 1; i < n; i++) {
            if (prices[i] < buyAt) {
                buyAt = prices[i];
            } else if (prices[i] - buyAt > profit) {
                profit = prices[i] - buyAt;
            }
        }
        return profit;
    }
};
