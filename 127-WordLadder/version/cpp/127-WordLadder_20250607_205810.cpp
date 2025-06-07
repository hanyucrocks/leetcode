// Last updated: 6/7/2025, 8:58:10 PM
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        unordered_set<string> st(wordList.begin(), wordList.end());
        st.erase(beginWord);
        while(!q.empty()){
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();
            if(word == endWord) return steps;
            // word = hat
            // aat, bat, cat
            for(int i = 0; i < word.size(); i++){
                char original = word[i];
                for(char ch = 'a'; ch <= 'z'; ch++){
                    word[i] = ch;
                    if(st.find(word) != st.end()){
                       st.erase(word);
                       q.push({word, steps +1}); 
                    }
                }
                word[i] = original;
            }
        }
        return 0;
    }
};