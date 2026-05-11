class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> state(numCourses, 0); // 0 unvisited, 1 visiting, 2 safe

        for (auto& prereq : prerequisites)
            adj[prereq[0]].push_back(prereq[1]);

        vector<int> res;
        for (int i = 0; i < numCourses; i++)
            if (!dfs(i, adj, state, res)) return {};

        return res;
    }

private:
    bool dfs(int course, vector<vector<int>>& adj, vector<int>& state, vector<int>& res) {
        if (state[course] == 2) return true;
        if (state[course] == 1) return false;

        state[course] = 1;

        for (int prereq : adj[course]) {
            if (!dfs(prereq, adj, state, res)) return false;
        }

        state[course] = 2;
        res.push_back(course);

        return true;
    }
};
