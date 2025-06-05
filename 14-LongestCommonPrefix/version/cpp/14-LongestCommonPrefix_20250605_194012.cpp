// Last updated: 6/5/2025, 7:40:12 PM
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";
        sort(strs.begin(), strs.end());
        string first = strs.front();
        string last = strs.back();
        int minlen = min(first.size(), last.size());
        int i = 0;
        while(i < minlen && first[i] == last[i]) i++;
        return first.substr(0, i);
    }
};