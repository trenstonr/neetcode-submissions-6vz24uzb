class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;

        unordered_map<char, int> window;
        int l = 0;
        for (int r = 0; r < s.size(); r++) {
            if (window.count(s[r])) {
                l = max(window[s[r]] + 1, l);
            }

            window[s[r]] = r;
            res = max(res, r - l + 1);
        }

        return res;
    }
};
