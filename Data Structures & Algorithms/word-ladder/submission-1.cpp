class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if (find(wordList.begin(), wordList.end(), endWord) == wordList.end() || 
            beginWord == endWord) return 0;

        unordered_map<string, vector<string>> adj;
        wordList.push_back(beginWord);
        for (string& word : wordList) {
            for (int i = 0; i < word.size(); i++) {
                string pattern = word;
                pattern[i] = '*';
                adj[pattern].push_back(word);
            }
        }

        unordered_set<string> seen;
        seen.insert(beginWord);
        queue<pair<string, int>> q; // word, level
        q.push({beginWord, 1});
    
        while (!q.empty()) {
            auto [word, level] = q.front();
            q.pop();

            for (int i = 0; i < word.size(); i++) {
                string pattern = word;
                pattern[i] = '*';
                for (string& next : adj[pattern]) {
                    if (next == endWord) return level + 1;
                    if (seen.count(next)) continue;
                    seen.insert(next);
                    q.push({next, level + 1});
                }
            }
        }

        return 0;
    }
};
