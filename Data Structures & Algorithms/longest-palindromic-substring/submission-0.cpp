class Solution {
public:
    string longestPalindrome(string s) {
        int maxLen = 0;
        int left = 0;
        
        for (int i = 0; i < s.size(); i++) {
            int l = i, r = i;
            while (l >= 0 && r < s.size() && s[l] == s[r]) {
                l--; r++;
            }

            int len = r - l + 1 - 2;
            if (len > maxLen) {
                maxLen = len;
                left = l + 1;
            }
        }

        for (int i = 0; i < s.size() - 1; i++) {
            int l = i, r = i + 1;
            if (s[l] != s[r]) continue;

            while (l >= 0 && r < s.size() && s[l] == s[r]) {
                l--; r++;
            }

            int len = r - l + 1 - 2;
            if (len > maxLen) {
                maxLen = len;
                left = l + 1;
            }
        }

        return s.substr(left, maxLen);
    }
};
