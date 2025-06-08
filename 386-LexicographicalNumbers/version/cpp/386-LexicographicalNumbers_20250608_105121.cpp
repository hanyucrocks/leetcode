// Last updated: 6/8/2025, 10:51:21 AM
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> nums;
        for(int i = 1; i <= n; i++) nums.push_back(i);
        sort(nums.begin(), nums.end(), [](int a, int b){
            return to_string (a) < to_string(b);
        });
        return nums;
    }
};