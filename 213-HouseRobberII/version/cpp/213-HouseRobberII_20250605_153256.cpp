// Last updated: 6/5/2025, 3:32:56 PM
class Solution {
int rob2(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n);
        if(n == 0) return 0;
        if(n==1) return nums[0];
        dp[n-1] = nums[n-1];
        dp[n-2] = max(nums[n-1], nums[n-2]);

        for(int i = n -3; i >= 0; i--){
            int take = nums[i] + dp[i+2];
            int nottake = dp[i+1];
            dp[i] = max(take, nottake);
        }
        return dp[0];
    }
public:
    int rob(vector<int>& nums) {
        // first and last are neighbours here.
        vector<int> temp1, temp2;
        int n = nums.size();
        if(n == 1) return nums[0];
        for(int i = 0; i < n; i++){
            if(i != 0) temp1.push_back(nums[i]);
            if(i != n - 1) temp2.push_back(nums[i]);
        }
        return max(rob2(temp1), rob2(temp2));
    }
};