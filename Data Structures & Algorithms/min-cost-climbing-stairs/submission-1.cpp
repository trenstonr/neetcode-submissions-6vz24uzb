class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int a = 0, b = 0;

        for (int i = 2; i <= cost.size(); i++) {
            int next = min(a + cost[i-2], b + cost[i-1]);
            a = b;
            b = next;
        }

        return b;
    }
};
