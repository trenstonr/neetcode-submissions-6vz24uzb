class Solution {
public:
    vector<int> partitionLabels(string s) {
        // x : 0, 3
        // y : 1, 4
        // z : 5, 7
        // b : 6, 9
        // i : 10, 10
        // s : 11, 11
        // l : 12, 12

        unordered_map<char, vector<int>> bounds;
        for (int i = 0; i < s.size(); i++) {
            if (bounds.count(s[i])) bounds[s[i]][1] = i;
            else bounds[s[i]] = {i, i};
        }

        vector<vector<int>> intervals;
        for (auto const& [k, v] : bounds) intervals.push_back(v);
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> merged = {{intervals[0]}};
        for (auto const& curr : intervals) {
            if (curr[0] <= merged.back()[1]) 
                merged.back()[1] = max(merged.back()[1], curr[1]);
            else
                merged.push_back(curr);
        }

        vector<int> res(merged.size());
        for (int i = 0; i < merged.size(); i++) {
            res[i] = merged[i][1] - merged[i][0] + 1;
        }

        return res;
    }
};
