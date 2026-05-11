class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;
        unordered_map<int, int> cache; // 0 visited, 1 visited true
        
        for (auto& prereq : prerequisites)
            adj[prereq[0]].push_back(prereq[1]);

        
        for (auto& [course, prereqs] : adj) {
            if (!dfs(course, adj, cache)) return false;
        }

        return true;
    }

private:
    bool dfs(int course, unordered_map<int, vector<int>>& adj, unordered_map<int, int>& cache) {
        if (cache.count(course)) return cache[course] ? true : false;

        cache[course] = 0;

        for (int prereq : adj[course]) {
            if (!dfs(prereq, adj, cache)) return false;
        }

        cache[course] = 1;

        return true;
    }
};
