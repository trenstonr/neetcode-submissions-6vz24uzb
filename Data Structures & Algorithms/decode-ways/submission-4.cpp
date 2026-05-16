class Solution {
public:
    int numDecodings(string s) {
        if (s.empty()) return 1;
        unordered_map<int, int> memo; // index : # of ways
        return dfs(0, s, memo);
    }

private:
    int dfs(int i, string& s, unordered_map<int, int>& memo) {
        if (i == s.size()) return 1;
        if (memo.count(i)) return memo[i];
        if (s[i] == '0') return 0;

        int res = dfs(i + 1, s, memo);

        if (i + 1 < s.size()) {
            int two = (s[i] - '0')*10 + (s[i + 1] - '0');
            if (two >= 10 && two <= 26) {
                res += dfs(i + 2, s, memo);
            }
        }

        return memo[i] = res;
    }
};
