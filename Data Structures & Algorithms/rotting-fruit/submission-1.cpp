class Solution {
    vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<vector<int>> q;
        for (int r = 0; r < grid.size(); r++) {
            for (int c = 0; c < grid[0].size(); c++) {
                if (grid[r][c] == 2) q.push({r, c, 0});
            }
        }

        int res = 0;
        while (!q.empty()) {
            auto v = q.front();
            q.pop();

            int r = v[0], c = v[1], l = v[2];
            res = max(res, l);

            for (int i = 0; i < 4; i++) {
                int nr = r + dir[i][0];
                int nc = c + dir[i][1];

                if (nr < 0 || nc < 0 || nr >= grid.size() ||
                    nc >= grid[0].size() || grid[nr][nc] != 1) {
                    continue;
                }

                grid[nr][nc] = 2;
                q.push({nr, nc, l + 1});
            }
        }

        for (int r = 0; r < grid.size(); r++) {
            for (int c = 0; c < grid[0].size(); c++) {
                if (grid[r][c] == 1) return -1;
            }
        }

        return res;
    }
};
