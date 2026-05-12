class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> parent(n);
        vector<int> rank(n, 1);
        iota(parent.begin(), parent.end(), 0); // <numeric>

        int components = n;

        for (auto& e : edges)
            if (union_set(e[0], e[1], parent, rank)) 
                components--;

        return components;
    }

private:
    int find_set(int v, vector<int>& parent) {
        if (v == parent[v]) return v;
        return parent[v] = find_set(parent[v], parent);
    }

    // returns whether a and b are in separate compoennts
    bool union_set(int a, int b, vector<int>& parent, vector<int>& rank) {
        a = find_set(a, parent);
        b = find_set(b, parent);

        if (a == b) return false;
        if (rank[a] < rank[b]) swap(a, b);
        
        parent[b] = a;
        rank[a] += rank[b];

        return true;
    }
};
