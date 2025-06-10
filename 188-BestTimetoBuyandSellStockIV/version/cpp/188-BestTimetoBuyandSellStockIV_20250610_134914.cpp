// Last updated: 6/10/2025, 1:49:14 PM
class Solution {
public:
    int f(int ind, int buy, int cap, vector<int> &prices, vector<vector<int>> &dp){
        int n = prices.size();
        if(ind == n) return 0;
        if(cap == 0) return 0;
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        long profit = 0;
        if(buy) profit = max(-prices[ind] + f(ind+1, 0, cap, prices, dp), f(ind+1, 1, cap, prices, dp));
        else profit = max(prices[ind] + f(ind+1, 1, cap-1, prices, dp), f(ind+1, 0, cap, prices, dp));
        return dp[ind][buy] = profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> after(2, vector<int> (k+1, 0));
        vector<vector<int>> cur(2, vector<int> (k+1, 0));
        // return f(0, 1, 2, prices, dp);
        // tabulation now
        // cap == 0, ind buy is antyhing
        // after and cur approach -> dp[ind+1] = after
        for(int ind = n - 1; ind>= 0; ind--){
            for(int buy = 0; buy <= 1; buy++){
                for(int cap = 1; cap <= k; cap++){
                    long profit = 0;
                    if (buy)
            profit = max(-prices[ind] + after[0][cap],
                         after[1][cap]);
        else
            profit = max(prices[ind] +after[1][cap-1],
                         after[0][cap]);
        cur[buy][cap] = profit;
                }
            }
            after = cur;
        }
        return after[1][k];
    }
};