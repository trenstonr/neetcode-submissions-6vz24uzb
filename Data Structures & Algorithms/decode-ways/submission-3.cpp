class Solution {
public:
    int numDecodings(string s) {
        if (s.empty()) return 1;
        unordered_map<int, int> num; // index : # of ways
        return dfs(0, s, num);
    }

private:
    int dfs(int i, string& s, unordered_map<int, int>& num) {
        int len = s.size() - i;
        if (len == 0) return 1;
        if (s[i] == '0') return 0;
        if (len == 1) return 1;

        int res = 0;
        if (num.count(i)) res += num[i];
        else res += num[i] = dfs(i + 1, s, num);

        int two = (s[i] - '0')*10 + (s[i + 1] - '0');
        if (two >= 10 && two <= 26) {
            if (num.count(i + 1)) res += num[i + 1];
            else res += num[i + 1] = dfs(i + 2, s, num);
        }

        return res;
    }
};
