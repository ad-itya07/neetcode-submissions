class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        for (auto edge: edges) {
            adj[edge[1]].push_back(edge[0]);
            adj[edge[0]].push_back(edge[1]);
        }

        vector<int> vis(n);
        queue<pair<int,int>> q; // prev, node

        q.push({-1,0});
        while (!q.empty()) {
            auto [prev, node] = q.front();
            q.pop();

            if (vis[node]) return false;
            
            vis[node] = 1;
            for (auto it: adj[node]) {
                if (prev != it) q.push({node, it});
            }
        }

        for (auto it: vis) if (it != 1) return false;

        return true;
    }
};
