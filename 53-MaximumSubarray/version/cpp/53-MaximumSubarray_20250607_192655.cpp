// Last updated: 6/7/2025, 7:26:55 PM
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // dp se kaise kare
        int n = nums.size();
        vector<int> dp(n);
        dp[0] = nums[0];
        int maxi = dp[0];
        for(int i = 1; i < n; i++){
            dp[i] = max(nums[i], dp[i-1] + nums[i]);
            maxi = max(maxi, dp[i]);
        }
        return maxi;
    }
};