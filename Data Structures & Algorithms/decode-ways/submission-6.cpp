class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();

        if (n == 0) return 1;
        if (s[0] == '0') return 0;
        if (n == 1) return 1;

        vector<int> dp(n + 1, 0);
        dp[n] = 1;

        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '0') continue;

            dp[i] += dp[i + 1];
            if (i + 1 < n && isValidTwo(s[i], s[i + 1])) 
                dp[i] += dp[i + 2];
        }

        return dp[0];

    }

private:
    bool isValidTwo(char a, char b) {
        int two = (a - '0')*10 + (b - '0');
        return (two >= 10 && two <= 26);
    }
};
