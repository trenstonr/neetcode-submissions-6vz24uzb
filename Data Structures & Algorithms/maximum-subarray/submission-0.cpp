class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = nums[0];
        
        int curr = 0;
        for (int n : nums) {
            curr += n;
            res = max(res, curr);
            if (curr < 0) curr = 0;
        }

        return res;
    }
};
