class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> cnt1(26, 0);
        for (char c : s1) cnt1[c - 'a']++;

        vector<int> cnt2(26, 0);
        int l = 0;
        for (int r = 0; r < s2.size(); r++) {
            cnt2[s2[r] - 'a']++;

            while (cnt2[s2[r] - 'a'] > cnt1[s2[r] - 'a']) {
                cnt2[s2[l] - 'a']--;
                l++;
            }

            if (cnt1 == cnt2) return true;
        }

        return false;
    }
};
