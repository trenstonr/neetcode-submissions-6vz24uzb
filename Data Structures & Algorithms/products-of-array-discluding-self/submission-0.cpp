class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // [1,  2,  4,  6] input
        // [1,  2,  8,  24] prefix
        // [48, 48, 24,  6] postfix
        // [48, 24, 12, 8] output

        vector<int> res(nums.size(), 1);

        int pre = 1;
        for (int i = 0; i < nums.size(); i++) {
            res[i] = pre;
            pre *= nums[i];
        }

        int post = 1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            res[i] *= post;
            post *= nums[i];
        }

        return res;

        // O(n), O(1)
    }
};
