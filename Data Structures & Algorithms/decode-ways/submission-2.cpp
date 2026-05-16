class Solution {
    unordered_map<string, int> cnt;
public:
    int numDecodings(string s) {
        if (s.empty()) return 1;
        if (s[0] == '0') return 0;
        if (s.size() == 1) return 1;

        string a = s.substr(1), b = s.substr(2);

        int res = 0;
        if (cnt.count(a)) res += cnt[a];
        else res += cnt[a] = numDecodings(a);

        int two = stoi(s.substr(0, 2));
        if (two >= 10 && two <= 26)
            if (cnt.count(b)) res += cnt[b];
            else res += cnt[b] = numDecodings(b);

        return res;

    }
};
