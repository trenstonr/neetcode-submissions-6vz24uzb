class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();

        int maxLen = 0;
        int start = 0;

        vector<vector<bool>> dp(n, vector<bool>(n, false));

        for (int i = 0; i < n; i++) {
            dp[i][i] = true;

            maxLen = 1;
            start = i;
        }

        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = true;
                
                maxLen = 2;
                start = i;
            }
        }

        for (int l = 3; l <= s.size(); l++) {
            for (int i = 0; i <= n - l; i++) {
                int j = i + l - 1;
                if (s[i] == s[j] && dp[i + 1][j - 1]) {
                    dp[i][i + l - 1] = true;
                    
                    maxLen = l;
                    start = i;
                }
            }
        }

        return s.substr(start, maxLen);
    }
};
