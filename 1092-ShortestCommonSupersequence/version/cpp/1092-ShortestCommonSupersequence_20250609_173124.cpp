// Last updated: 6/9/2025, 5:31:24 PM
class Solution {
public:
    int lcs(string s1, string s2){
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
        for(int i = 0; i <= n; i++) dp[i][0] = 0;
        for(int j = 0; j <= m; j++) dp[0][j] = 0;
        for(int ind1 = 1; ind1 <= n; ind1++){
            for(int ind2 = 1; ind2 <= m; ind2++){
                // if same
                if(s1[ind1-1] == s2[ind2-1]) dp[ind1][ind2] = 1 + dp[ind1-1][ind2-1];
                else dp[ind1][ind2] = max(dp[ind1-1][ind2], dp[ind1][ind2-1]);
            }
        }
        return dp[n][m];
    }
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
        for(int i = 0; i <= n; i++) dp[i][0] = 0;
        for(int j = 0; j <= m; j++) dp[0][j] = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                // if same
                if(str1[i-1] == str2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        string ans = "";
        int i = n;
        int j = m;
        while(i > 0 && j > 0){
            if(str1[i-1] == str2[j-1]){
                ans += str2[j-1];
                i--; j--;
            }
            else if(dp[i-1][j] > dp[i][j-1]){
                ans += str1[i-1];
                i--;
            }
            else{
                ans += str2[j-1];
                j--;
            }
        }
        while(i > 0){ 
            ans += str1[i-1]; i--;
        }
        while(j > 0){
            ans += str2[j-1]; j--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};