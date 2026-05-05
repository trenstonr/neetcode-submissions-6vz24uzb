class Solution {
public:
    bool canJump(vector<int>& nums) {
        int i = nums.size() - 1;

        while (i > 0) {
            int j = i - 1;
            while (j >= 0) {
                if (nums[j] >= i - j) {
                    i = j;
                    break;
                }
                j--;
            }

            if (i != j) return false;
        }

        return true;
    }
};
