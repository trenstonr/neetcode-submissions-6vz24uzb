class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // range [1, n]

        for (int n : nums) {
            if (nums[abs(n) - 1] < 0) return abs(n);
            nums[abs(n) - 1] *= -1;
        }

        return -1;
    }
};
