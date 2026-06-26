//Approach 1: brute force
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = prices[0];
        int profit = 0;

        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] < buy)
                buy = prices[i];
            else {
                while (i < prices.size() - 1 && prices[i] <= prices[i + 1]) {
                    i++;
                }
                profit = profit + (prices[i] - buy);
                
                // Only update buy if another day exists
                if (i < prices.size() - 1)
                    buy = prices[i + 1];

            }
        }
        return profit;
    }
};
//Approach 2: Greedy algo - just think about doing profit only when the next ekement is greater than prev element
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] > prices[i - 1])
                profit += prices[i] - prices[i - 1];
        }
        return profit;
    }
};
