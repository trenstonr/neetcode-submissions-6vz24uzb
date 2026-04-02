class Solution {
public:
    int characterReplacement(string s, int k) {
        // size <= maxFreq + k
        // while (size - maxFreq > k) { // shrink // }

        int res = 0;

        vector<int> count(26, 0);
        int maxFreq = 0;

        int l = 0;
        for (int r = 0; r < s.size(); r++) {
            count[s[r] - 'A']++;
            maxFreq = max(maxFreq, count[s[r] - 'A']);

            while (r - l + 1 - maxFreq > k) {
                count[s[l] - 'A']--;
                l++;
            }

            res = max(res, r - l + 1);
        }

        return res;
    }
};
