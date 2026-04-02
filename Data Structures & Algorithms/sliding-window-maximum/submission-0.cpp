class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int l = 0, r = k - 1;

        vector<int> res;
        while (r < nums.size()) {
            res.push_back(*max_element(nums.begin() + l, nums.begin() + r + 1));
            l++;
            r++;
        }

        return res;
    }
};
