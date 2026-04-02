class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;

        vector<int> bank(26, 0);

        for (char c : s) bank[c - 'a']++;
        for (char c : t) bank[c - 'a']--;

        for (int n : bank) {
            if (n != 0) return false;
        }

        return true;

        // O(n) since we traverse both strings once
        // O(26) -> O(1)
    }
};
