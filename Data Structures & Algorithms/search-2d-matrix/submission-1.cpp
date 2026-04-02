class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        int l = 0, r = n * m - 1;

        while (l <= r) {
            int mid = midpoint(l, r);
            int x = matrix[mid / m][mid % m];

            if (x == target) return true;
            else if (x < target) l = mid + 1;
            else r = mid - 1;
        }

        return false;
    }
};
