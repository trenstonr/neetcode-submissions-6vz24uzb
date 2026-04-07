class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>> maxHeap;

        for (auto p : points) {
            int d = p[0]*p[0] + p[1]*p[1];
            maxHeap.push({d, p[0], p[1]});
        }

        while (maxHeap.size() > k) maxHeap.pop();

        vector<vector<int>> res;
        while (!maxHeap.empty()) {
            vector<int> p = maxHeap.top();
            maxHeap.pop();
            res.push_back({p[1], p[2]});
        }

        return res;
    }
};
