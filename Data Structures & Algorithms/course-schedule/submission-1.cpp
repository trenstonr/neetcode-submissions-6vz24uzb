class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> state(numCourses, 0); // 0 unvisited, 1 visiting, 2 safe

        for (auto& prereq : prerequisites)
            adj[prereq[0]].push_back(prereq[1]);

        for (int i = 0; i < numCourses; i++)
            if (!dfs(i, adj, state)) return false;

        return true;
    }

private:
    bool dfs(int course, vector<vector<int>>& adj, vector<int>& state) {
        if (state[course] == 2) return true;
        if (state[course] == 1) return false;

        state[course] = 1;

        for (int prereq : adj[course]) {
            if (!dfs(prereq, adj, state)) return false;
        }

        state[course] = 2;

        return true;
    }
};
