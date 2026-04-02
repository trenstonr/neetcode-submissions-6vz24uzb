class Solution {
public:
    int maxArea(vector<int>& heights) {
        int res = 0;

        int l = 0, r = heights.size() - 1;
        while (l < r) {
            int size = min(heights[l], heights[r]) * (r - l);
            res = max(res, size);

            if (heights[l] < heights[r]) l++;
            else if (heights[l] > heights[r]) r--;
            else l++;
        }

        return res;
    }

    // O(n), O(1)
};
