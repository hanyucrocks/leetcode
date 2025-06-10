// Last updated: 6/10/2025, 4:43:49 PM
class Solution {
public:
    int f(int ind, int prevind, vector<int> &arr, int n, vector<vector<int>> &dp){
        if (ind == n) return 0;
        if(dp[ind][prevind+1]!=-1) return dp[ind][prevind+1];
        int len = 0 + f(ind+1, prevind, arr, n ,dp);
        // take
        if(prevind == -1 || arr[ind] > arr[prevind]){
            len = max(len, 1 + f(ind+1, ind, arr, n, dp));
        }
        return dp[ind][prevind+1] = len;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int> (n+1, 0));
        for(int ind = n - 1; ind >= 0; ind--){
            for(int prev_ind = ind-1; prev_ind>=-1; prev_ind--){
                int len = 0 + dp[ind+1][prev_ind+1];
                if(prev_ind == -1 || nums[ind] >nums[prev_ind]){
                    len = max(len, 1 + dp[ind+1][ind+1]);
                }
                dp[ind][prev_ind+1] = len;
            }
        }
        return dp[0][-1+1];
    }
};