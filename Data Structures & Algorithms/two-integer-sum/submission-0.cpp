class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> num_to_idx;

        for (int i = 0; i < nums.size(); i++) {
            if (num_to_idx.count(target - nums[i])) {
                return {num_to_idx[target - nums[i]], i};
            }
            num_to_idx[nums[i]] = i;
        }

        return {-1};

        // O(n), O(n)
    }
};
