class Solution {
public:
    int jump(vector<int>& nums) {
        int res = 0;

        int i = nums.size() - 1;
        while (i > 0) {
            int next;
            int j = i - 1;
            while (j >= 0) {
                if (nums[j] >= i - j) next = j;
                j--;
            }
            
            i = next;
            res++;
        }

        return res;
    }
};
