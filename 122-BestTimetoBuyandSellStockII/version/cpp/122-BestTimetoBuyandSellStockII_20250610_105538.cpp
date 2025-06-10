// Last updated: 6/10/2025, 10:55:38 AM
class Solution {
public:
    int f(int ind, int buy, vector<int> &prices, vector<vector<int>> &dp){
        int n = prices.size();
        if(ind == n) return 0;
        if(dp[ind][buy] != -1) return dp[ind][buy];
        int profit = INT_MIN;
        if(buy){
            profit = max(-prices[ind] + f(ind+1, 0, prices, dp), 0 + f(ind+1, 1, prices, dp));
        }
        else profit = max(prices[ind] + f(ind+1, 1, prices, dp), f(ind+1, 0, prices, dp));
        return dp[ind][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<long> ahead(2, 0), cur(2, 0);
        ahead[0] = ahead[1] = 0;
        for(int ind = n - 1; ind >= 0; ind--){
            for(int buy =0; buy <=1; buy++){
                long profit = INT_MIN;
        if(buy){
            profit = max(-prices[ind] + ahead[0], 0 + ahead[1]);
        }
        else profit = max(prices[ind] + ahead[1], ahead[0]);
        cur[buy] = profit;
            }
            ahead = cur;
        }
        // return f(0, 1, prices, dp);
        return ahead[1];
    }
};