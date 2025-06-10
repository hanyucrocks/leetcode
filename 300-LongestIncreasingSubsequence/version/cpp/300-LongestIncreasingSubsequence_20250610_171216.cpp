// Last updated: 6/10/2025, 5:12:16 PM
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
       vector<int> dp(n, 1);
       int maxi = INT_MIN;
       for(int ind = 0; ind < n; ind++){
        for(int prev= 0; prev < ind; prev++){
            if(nums[prev]<nums[ind]) dp[ind] = max(dp[ind], 1 + dp[prev]); 
        }
        maxi = max(maxi, dp[ind]);
       }
       return maxi;
    }
};