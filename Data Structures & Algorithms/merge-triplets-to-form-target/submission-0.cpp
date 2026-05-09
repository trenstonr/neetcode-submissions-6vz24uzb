class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<int> mx = {0, 0, 0};

        for (auto& v : triplets) {
            if (v[0] > target[0] || v[1] > target[1] || v[2] > target[2]) {
                continue;
            }

            for (int i = 0; i < 3; i++) {
                mx[i] = max(mx[i], v[i]);
            }
        }

        return mx == target;
    }
};
