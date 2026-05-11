class Solution {
public:
    void solve(vector<vector<char>>& board) {
        // O cannot be surrounded if:
        // on border, connect to O on border (dir/indir)

        // X -> X, Y -> cannot be surrounded, O -> can be surrounded

        int n = board.size(), m = board[0].size();

        for (int r = 0; r < n; r++) {
            if (board[r][0] == 'O') dfs(r, 0, board);
            if (board[r][m - 1] == 'O') dfs(r, m - 1, board);
        }

        for (int c = 0; c < m; c++) {
            if (board[0][c] == 'O') dfs(0, c, board);
            if (board[n - 1][c] == 'O') dfs(n - 1, c, board);
        }

        for (int r = 0; r < n; r++) {
            for (int c = 0; c < m; c++) {
                if (board[r][c] == 'Y') board[r][c] = 'O';
                else if (board[r][c] == 'O') board[r][c] = 'X';
            }
        }
    }

private:
    vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    void dfs(int r, int c, vector<vector<char>>& board) {
        board[r][c] = 'Y';

        for (int i = 0; i < 4; i++) {
            int nr = r + dir[i][0];
            int nc = c + dir[i][1];

            if (nr < 0 || nc < 0 || nr >= board.size() || nc >= board[0].size())
                continue;
            
            if (board[nr][nc] != 'O')
                continue;
            
            dfs(nr, nc, board);
        }
    }
};
