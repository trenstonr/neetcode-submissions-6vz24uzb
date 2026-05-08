class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int res = 0;
        unordered_map<int, int> hm;

        for (int n : nums) {
            if (hm.count(n) && hm[n] != 0) continue;

            hm[n] = 1 + hm[n - 1] + hm[n + 1];

            hm[n - hm[n - 1]] = hm[n];
            hm[n + hm[n + 1]] = hm[n];

            res = max(res, hm[n]);
        }

        return res;
    }
};

// {   n: hm[n]
//     0: 0
//     1: 1
//     2: 0
// }