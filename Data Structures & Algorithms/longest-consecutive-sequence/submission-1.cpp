class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;

        unordered_map<int, int> hm; // num : len_sequence

        int res = 1;
        for (int n : nums) {
            if (hm.count(n)) continue;

            if (hm.count(n - 1)) {
                hm[n] = 1 + hm[n - 1];
                res = max(res, hm[n]);
            } else {
                hm[n] = 1;
            }
            
            while (hm.count(n + 1)) {
                hm[n + 1] = 1 + hm[n];
                res = max(res, hm[n + 1]);
                n++;
            }
        }

        return res;
    }
};
