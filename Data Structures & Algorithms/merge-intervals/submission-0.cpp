class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> res = {{intervals[0]}};
        for (auto const& curr : intervals) {
            if (curr[0] <= res.back()[1]) 
                res.back()[1] = max(res.back()[1], curr[1]);
            else
                res.push_back(curr);
        }

        return res;
    }
};
