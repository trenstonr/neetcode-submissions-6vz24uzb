class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;

        for (string& str : strs) {
            vector<int> freq(26, 0);
            for (char c : str) {
                freq[c - 'a']++;
            }

            string key = "";
            for (int f : freq) {
                key += "#" + to_string(f);
            }

            groups[key].push_back(str);
        }

        vector<vector<string>> res;
        for (auto& [_, group] : groups) {
            res.push_back(group);
        }

        return res;

        // O(n * k) ; n -> # of strs, k -> max str length
        // O(n * k)
    }
};
