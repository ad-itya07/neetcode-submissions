class Solution {
public:
    bool dfs(int node, int prev, vector<int>& vis, vector<int> adj[]) {
        if (vis[node]) return true;

        vis[node] = 1;

        bool loop = false;
        for (auto adjNode: adj[node]) {
            if (prev == -1 || adjNode != prev) {
                loop = loop | dfs(adjNode, node, vis, adj);
            }
        }

        return loop;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        for (auto it: edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        } 

        vector<int> vis(n,0);
        bool loop = true;
        // for (int i=0; i<n; i++) {
            // if (!vis[i]) {
        int prev = -1;
        loop = loop & dfs(0, prev, vis, adj);
            // }
        // }

        if (loop) return false;

        for (int i=0; i<n; i++) {
            if (!vis[i]) return false;
        }

        return true;

    }
};
