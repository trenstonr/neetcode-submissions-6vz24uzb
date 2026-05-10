class Solution {
    vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        for (int r = 0; r < grid.size(); r++) {
            for (int c = 0; c < grid[0].size(); c++) {
                if (grid[r][c] == 0) q.push({r, c});
            }
        }

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nr = r + dir[i][0];
                int nc = c + dir[i][1];

                if (nr < 0 || nc < 0 || nr >= grid.size() ||
                    nc >= grid[0].size() || grid[nr][nc] != INT_MAX) {
                    continue;
                }

                grid[nr][nc] = 1 + grid[r][c];
                q.push({nr, nc});
            }
        }
    }
};
