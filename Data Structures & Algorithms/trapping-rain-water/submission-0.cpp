class Solution {
public:
    int trap(vector<int>& height) {
        // area[i] == min(maxL, maxR) - heights[i]

        vector<int> maxR(height.size());
        maxR.back() = height.back();
        for (int i = height.size() - 2; i >= 0; i--) {
            if (height[i] > maxR[i + 1]) maxR[i] = height[i];
            else maxR[i] = maxR[i + 1];
        }

        int res = 0;

        int maxL = height[0];
        for (int i = 1; i < height.size(); i++) {
            maxL = max(maxL, height[i]);
            int area = min(maxL, maxR[i]) - height[i];
            if (area > 0) res += area;
        }

        return res;
    }
};
