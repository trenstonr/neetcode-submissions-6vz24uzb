class Solution {
public:
    int jump(vector<int>& nums) {
        int res = 0;
        int l = 0, r = 0;

        while (r < nums.size() - 1) {
            int nr = -1;

            for (int i = l; i <= r; i++) {
                nr = max(nr, i + nums[i]);
            }
            
            l = r + 1;
            r = nr;

            res++;
        }

        return res;
    }
};
