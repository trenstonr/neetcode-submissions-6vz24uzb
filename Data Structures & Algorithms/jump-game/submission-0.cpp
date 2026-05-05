class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<bool> reach(nums.size(), false);
        reach[0] = true;

        for (int i = 0; i < nums.size(); i++) {
            if (!reach[i]) continue;
            for (int j = 1; j <= nums[i]; j++) {
                reach[i + j] = true;
            }
        }

        return reach[nums.size() - 1];
    }
};
