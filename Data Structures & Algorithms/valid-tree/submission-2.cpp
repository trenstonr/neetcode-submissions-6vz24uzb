class Solution {public:
    bool validTree(int n, vector<vector<int>>& edges) { 
        // no cycles, connnected (n nodes -> n-1 edges)
        if (edges.size() != n - 1) return false;

        vector<vector<int>> adj(n);
        vector<bool> visited(n);

        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        if (!dfs(0, visited, adj, -1)) return false;
        for (bool v : visited) if (!v) return false;

        return true;
    }

private:
    bool dfs(int node, vector<bool>& visited, vector<vector<int>>& adj, int parent) {
        visited[node] = true;

        for (int nei : adj[node]) {
            if (nei == parent) continue;
            if (visited[nei]) return false;
            if (!dfs(nei, visited, adj, node)) return false;
        }

        return true;
    }
};
