class Solution {
public:
    int jump(vector<int>& nums) {
        int res = 0;

        int l = 0, r = 0;
        while (r < nums.size() - 1) {
            int start = l, end = r;

            for (int i = start; i <= end; i++) 
                r = max(r, i + nums[i]);

            l = l + 1;
            res++;
        }

        return res;
    }
};
