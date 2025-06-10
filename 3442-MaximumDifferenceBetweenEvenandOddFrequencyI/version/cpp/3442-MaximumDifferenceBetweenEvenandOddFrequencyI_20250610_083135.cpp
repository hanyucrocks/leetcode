// Last updated: 6/10/2025, 8:31:35 AM
class Solution {
public:
    int maxDifference(string s) {
       vector<int> count(26);
       for (auto &ch : s) count[ch-'a']++;

       int max_odd = 0, min_even = INT_MAX;
       for(int i = 0; i < 26; i++){
        if(count[i] && count[i] % 2) max_odd =max(max_odd, count[i]);
        else if(count[i]) min_even = min(min_even, count[i]);
       }
        return max_odd - min_even;
    }
};