class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) return 1;

        int first = 1, second = 2;

        for (int i = 2; i < n; i++) {
            int next = first + second;
            first = second;
            second = next;
        }

        return second;
    }
};
