class Solution {
public:
    string minWindow(string s, string t) {
        if (t.empty()) return "";

        unordered_map<char, int> countT, window;
        for (char c : t) countT[c]++;
        
        int have = 0, need = countT.size();

        pair<int, int> res = {-1, -1};
        int resLen = INT_MAX;

        int l = 0;
        for (int r = 0; r < s.size(); r++) {
            window[s[r]]++;
            if (countT.count(s[r]) && window[s[r]] == countT[s[r]]) {
                have++;
            }

            while (have == need) {
                if (r - l + 1 < resLen) {
                    res = {l, r};
                    resLen = r - l + 1;
                }

                window[s[l]]--;
                if (countT.count(s[l]) && window[s[l]] < countT[s[l]]) {
                    have--;
                }
                l++;
            }
        }

        if (resLen == INT_MAX) return "";
        return s.substr(res.first, resLen);
    }
};
