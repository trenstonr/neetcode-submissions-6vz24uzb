class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<vector<int>> buckets(nums.size() + 1);

        unordered_map<int, int> freq;
        for (int n : nums) freq[n]++;

        for (auto [n, f] : freq) {
            buckets[f].push_back(n);
        }

        vector<int> res;
        int size = 0;
        for (int i = buckets.size() - 1; i >= 0; i--) {
            for (int n : buckets[i]) {
                res.push_back(n);
                size++;
                if (size == k) return res;
            }
        }

        return res;
    }
};
