// Last updated: 6/10/2025, 12:58:00 PM
class Solution {
public:
    int f(int ind, int buy, int cap, vector<int> &prices, vector<vector<vector<int>>> & dp){
        int n = prices.size();
        if(ind == n) return 0;
        if(cap == 0) return 0;
        if(dp[ind][buy][cap]!=-1) return dp[ind][buy][cap];
        long profit = 0;
        if(buy) profit = max(-prices[ind] + f(ind+1, 0, cap, prices, dp), f(ind+1, 1, cap, prices, dp));
        else profit = max(prices[ind] + f(ind+1, 1, cap-1, prices, dp), f(ind+1, 0, cap, prices, dp));
        return dp[ind][buy][cap] = profit;

    }
    int maxProfit(vector<int>& prices) {
        // at max two transactions
        // 3 - 0 == 3 and 4 - 1== 3 toh 3 
        /*
        cap = 2;
        if(buy) -price[ind] + f(ind+1, 0, cap) -> buy
                0 + f(ind+1, 1, cap) -> not buying    max lelo dono ka
        else // sell and not sell
                prices[ind] + f(ind+1, 1, cap- 1) -> sell
                o + f(ind+1, 0, cap) -> not sell max lelo dono ka


                this is a 3D dp, not a 2D dp babyyy
        */
        
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (2, vector<int> (3, -1)));
        return f(0, 1, 2, prices, dp);
    }
};