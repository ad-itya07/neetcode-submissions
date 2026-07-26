class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<int> vis(n,0);

        for (auto edge: edges) {
            vis[edge[1]]++;
            if (vis[edge[1]] > 1) return false;
        }

        return true;
    }
};
