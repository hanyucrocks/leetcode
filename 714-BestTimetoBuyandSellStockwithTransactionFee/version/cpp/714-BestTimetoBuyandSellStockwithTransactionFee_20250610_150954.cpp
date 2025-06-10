// Last updated: 6/10/2025, 3:09:54 PM
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<long>> dp(n+1, vector<long> (2, 0));
        dp[n][0] = dp[n][1] = 0;
        for(int ind = n - 1; ind >= 0; ind--){
            for(int buy =0; buy <=1; buy++){
                long profit = INT_MIN;
        if(buy){
            profit = max(-prices[ind] -fee + dp[ind+1][0], 0 + dp[ind+1][1]);
        }
        else profit = max(prices[ind] + dp[ind+1][1], dp[ind+1][0]);
        dp[ind][buy] = profit;
            }
        }
        // return f(0, 1, prices, dp);
        return dp[0][1];
    }
};