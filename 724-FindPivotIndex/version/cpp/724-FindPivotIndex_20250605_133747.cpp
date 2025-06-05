// Last updated: 6/5/2025, 1:37:47 PM
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int total= accumulate(nums.begin(), nums.end(), 0);
        int lefttotal = 0;

        for(int i = 0; i < n; i++){
            int righttotal = total - lefttotal -nums[i];
            if(righttotal == lefttotal) return i;
            lefttotal += nums[i];
        }
        return -1;
    }
};