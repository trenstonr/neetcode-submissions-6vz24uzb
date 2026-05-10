class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res = 0;

        for (int r = 0; r < grid.size(); r++) {
            for (int c = 0; c < grid[0].size(); c++) {
                if (grid[r][c] == 1) {
                    res = max(res, dfs(r, c, grid));
                }
            }
        }

        return res;
    }

private:
    vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int dfs(int r, int c, vector<vector<int>>& grid) {
        grid[r][c] = 0;
        
        int area = 1;
        for (int i = 0; i < 4; i++) {
            int nr = r + dir[i][0];
            int nc = c + dir[i][1];

            if (nr < 0 || nc < 0 || nr >= grid.size() ||
                nc >= grid[0].size() || grid[nr][nc] == 0)
                continue;
            
            area += dfs(nr, nc, grid);
        }

        return area;
    }
};
