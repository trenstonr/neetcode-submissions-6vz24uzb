class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        
        return max(
            helper(vector<int>(nums.begin() + 1, nums.end())),
            helper(vector<int>(nums.begin(), nums.end() - 1))
        );
    }

private:
    int helper(vector<int> nums) {
        if (nums.size() == 1) return nums[0];

        int a = 0, b = 0;
        for (int num : nums) {
            int temp = max(b, num + a);
            a = b;
            b = temp;
        }

        return b;
    }
};
