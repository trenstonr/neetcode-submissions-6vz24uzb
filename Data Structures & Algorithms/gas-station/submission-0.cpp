class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();

        for (int start = 0; start < n; start++) {
            int tank = gas[start];
            int curr = start;
            
            while (true) {
                tank -= cost[curr % n];
                curr++;
                if (tank < 0) break;
                if (curr % n == start) return start;
                tank += gas[curr % n];
            }
        }

        return -1;
    }
};
