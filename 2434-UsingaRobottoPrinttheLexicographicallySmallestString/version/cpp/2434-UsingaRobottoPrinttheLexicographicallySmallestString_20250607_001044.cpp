// Last updated: 6/7/2025, 12:10:44 AM
class Solution {
public:
    string robotWithString(string s) {
        vector<int> freq(26, 0);
    for (char c : s) freq[c - 'a']++;

    string t = "";
    string p = "";
    int i = 0;

    for (char c : s) {
        t.push_back(c);
        freq[c - 'a']--;
        char minChar = 'a';
        while (minChar <= 'z' && freq[minChar - 'a'] == 0) {
            minChar++;
        }

        while (!t.empty() && (minChar > 'z' || t.back() <= minChar)) {
            p.push_back(t.back());
            t.pop_back();
        }
    }
    while (!t.empty()) {
        p.push_back(t.back());
        t.pop_back();
    }

    return p;
    }
};