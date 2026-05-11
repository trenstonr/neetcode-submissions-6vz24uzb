class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        unordered_set<long long> pacific;
        for (int r = 0; r < heights.size(); r++) {
            dfs(r, 0, pacific, heights);
        }
        for (int c = 0; c < heights[0].size(); c++) {
            dfs(0, c, pacific, heights);
        }

        unordered_set<long long> atlantic;
        for (int r = 0; r < heights.size(); r++) {
            dfs(r, heights[0].size() - 1, atlantic, heights);
        }
        for (int c = 0; c < heights[0].size(); c++) {
            dfs(heights.size() - 1, c, atlantic, heights);
        }

        vector<vector<int>> res;
        for (long long entry : pacific) {
            if (atlantic.count(entry)) 
                res.push_back({
                    (int)(entry / (long long)heights[0].size()), 
                    (int)(entry % (long long)heights[0].size())
                });
        }

        return res;
    }

private:
    vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    void dfs(int r, int c, unordered_set<long long>& reach, vector<vector<int>>& heights) {
        long long entry = (long long)r * heights[0].size() + c;
        reach.insert(entry);

        for (int i = 0; i < 4; i++) {
            int nr = r + dir[i][0];
            int nc = c + dir[i][1];
            long long nentry = (long long)nr * heights[0].size() + nc;

            if (nr < 0 || nc < 0 || nr >= heights.size() || nc >= heights[0].size())
                continue;
                
            if (reach.count(nentry) || heights[nr][nc] < heights[r][c])
                continue;

            dfs(nr, nc, reach, heights);
        }
    }
};
