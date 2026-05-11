class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        // no cycles, connnected
        vector<vector<int>> adj(n);

        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        
        vector<int> state(n); // 0 unvisited, 1 visiting
        int count = 0;

        if (!dfs(0, state, adj, -1, count)) return false;

        return count == n;
    }

private:
    bool dfs(int node, vector<int>& state, vector<vector<int>>& adj, int parent, int& count) {
        state[node] = 1;
        count++;

        for (int nei : adj[node]) {
            if (nei == parent) continue;
            if (state[nei] == 1) return false;
            if (!dfs(nei, state, adj, node, count)) return false;
        }

        return true;
    }
};
