class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        vector<int> size(n + 1, 1);
        vector<int> parent(n + 1);
        iota(parent.begin(), parent.end(), 0);

        int last = -1;
        for (int i = 0; i < n; i++) {
            int a = edges[i][0], b = edges[i][1];
            if (union_set(a, b, parent, size)) last = i;
        }

        return last != -1 ? edges[last] : vector<int>(1, -1);
    }

private:
    int find_set(int v, vector<int>& parent) {
        if (v == parent[v]) return v;
        return parent[v] = find_set(parent[v], parent);
    }

    // true if its a redundant connection
    bool union_set(int a, int b, vector<int>& parent, vector<int>& size) {
        a = find_set(a, parent);
        b = find_set(b, parent);

        if (parent[a] == parent[b]) return true;

        if (size[b] > size[a]) swap(a, b);

        parent[b] = parent[a];
        size[a] += size[b];

        return false;
    }
};
