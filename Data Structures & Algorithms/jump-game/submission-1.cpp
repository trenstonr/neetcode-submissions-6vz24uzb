class Solution {
public:
    bool canJump(vector<int>& nums) {
        int i = nums.size() - 1;

        while (i > 0) {
            int next = -1;
            int j = i - 1;
            while (j >= 0) {
                if (nums[j] >= i - j) next = j;
                j--;
            }
            if (next == -1) return false;
            i = next;
        }

        return true;
    }
};
