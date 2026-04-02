class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prod = 1;
        int z = 0;
        for (int n : nums) {
            if (n != 0) prod *= n;
            else z++;
        }

        if (z > 1) return vector<int>(nums.size(), 0);

        vector<int> res(nums.size(), 1);
        
        for (int i = 0; i < nums.size(); i++) {
            if (z > 0) {
                res[i] = (nums[i] == 0) ? prod : 0;
            } else {
                res[i] = prod / nums[i];
            }
        }

        return res;
    }
};
