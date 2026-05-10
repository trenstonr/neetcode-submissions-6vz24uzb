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
        if (r < 0 || 
            r >= grid.size() || 
            c < 0 || 
            c >= grid[0].size() ||
            grid[r][c] == '0') {
                return;
            }  

        grid[r][c] = '0';
        for (int i = 0; i < 4; i++) {
            dfs(r + dir[i][0], c + dir[i][1], grid);
        }
    }
};
