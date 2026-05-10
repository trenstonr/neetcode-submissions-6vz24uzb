class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        for (int r = 0; r < grid.size(); r++) {
            for (int c = 0; c < grid[0].size(); c++) {
                if (grid[r][c] == '1') {
                    dfs(r, c, grid);
                    res++;
                }
            }
        }

        return res;
    }

private:
    vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    void dfs(int r, int c, vector<vector<char>>& grid) {
        grid[r][c] = '0';

        for (int i = 0; i < 4; i++) {
            int nr = r + dir[i][0];
            int nc = c + dir[i][1];

            if (nr < 0 || nc < 0 || nr >= grid.size() ||
                nc >= grid[0].size() || grid[nr][nc] == '0')
                continue;
            
            dfs(nr, nc, grid);
        }
    }
};
