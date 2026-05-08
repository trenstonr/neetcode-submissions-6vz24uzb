class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int res = 0;
        unordered_map<int, int> hm;

        for (int n : nums) {
            if (hm.count(n)) continue;

            int left = (hm.find(n - 1) != hm.end() ? hm[n - 1] : 0);
            int right = (hm.find(n + 1) != hm.end() ? hm[n + 1] : 0);
            int sum = left + right + 1;

            hm[n] = sum;
            hm[n - left] = sum;
            hm[n + right] = sum;

            res = max(res, sum);
        }

        return res;
    }
};

// {   n: hm[n]
//     0: 0
//     1: 1
//     2: 0
// }