class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];

        int a = nums[0], b = max(nums[0], nums[1]);

        for (int i = 2; i < nums.size(); i++) {
            int next = max(b, a + nums[i]);
            a = b;
            b = next;
        }

        return b;
    }
};
