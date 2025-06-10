// Last updated: 6/10/2025, 2:48:23 PM
class Solution {
public:
    int f(int ind, int buy, vector<int> &prices, vector<vector<int>> &dp){
        int n = prices.size();
        if(ind>=n) return 0;
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        long profit = 0;
        if(buy){
            profit = max(-prices[ind] + f(ind+1, 0, prices, dp), f(ind+1, 1, prices, dp));
        }
        else profit =  max(prices[ind] + f(ind+2, 1, prices, dp), f(ind+1, 0, prices, dp));
        return dp[ind][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        // buy, sell, cooldown, buy sell cooldown
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int> (2, -1));
        return f(0, 1, prices, dp);
    }
};