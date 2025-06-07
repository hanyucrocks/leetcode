// Last updated: 6/7/2025, 2:54:42 PM
class Solution {
public:
    string clearStars(string s) {
        priority_queue<pair<char, int>, vector<pair<char, int>>,
                       greater<pair<char, int>>>
            pq;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '*') {
                auto [c, i] = pq.top();
                pq.pop();
                s[-i] = ' ';
            } else
                pq.push({s[i], -i});
        }
        string res = "";
        for (char c : s) {
            if (c != ' ' && c != '*') {
                res.push_back(c);
            }
        }
        return res;
    }
};