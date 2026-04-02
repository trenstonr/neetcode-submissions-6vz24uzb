class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (vector<char>& row : board) {
            unordered_set<int> r_seen;
            for (char cell : row) {
                if (cell == '.') continue;
                if (r_seen.count(cell)) return false;
                r_seen.insert(cell);
            }
        }

        for (int col = 0; col < 9; col++) {
            unordered_set<int> c_seen;
            for (vector<char>& row : board) {
                char cell = row[col];
                if (cell == '.') continue;
                if (c_seen.count(cell)) return false;
                c_seen.insert(cell);
            }
        }

        for (int r = 0; r < 9; r += 3) {
            for (int c = 0; c < 9; c += 3) {
                unordered_set<int> b_seen;
                for (int s = r; s < r + 3; s++) {
                    for (int d = c; d < c + 3; d++) {
                        char cell = board[s][d];
                        if (cell == '.') continue;
                        if (b_seen.count(cell)) return false;
                        b_seen.insert(cell);
                    }
                }
            }
        }

        return true;
    }
};
