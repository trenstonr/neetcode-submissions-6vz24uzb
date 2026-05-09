class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());

        int res = 0;
        for (int n : numSet) {
            if (numSet.find(n - 1) != numSet.end()) continue;
            
            int length = 1;
            while (numSet.find(n + length) != numSet.end()) length++;
            res = max(res, length);
        }

        return res;
    }
};
