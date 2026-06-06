class Solution {
   public:
   bool isValid(int r, int c, vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size(); 

        return r >= 0 && r < m && c >=0 && c<n;
   }
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        priority_queue < pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int,int>>>> pq;

        vector<vector<int>> dis(m, vector<int> (n, INT_MAX));
        vector<vector<int>> vis(m, vector<int> (n, 0));

        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (grid[i][j] == 0) {
                    pq.push({0, {i,j}});
                    dis[i][j] = 0;
                }
            }
        }

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        while (!pq.empty()) {
            int dist = pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            pq.pop();

            if (dist > dis[r][c]) continue;
            
            vis[r][c] = 1;
            for (int i=0; i<4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (isValid(nr, nc, grid) && grid[nr][nc] == INT_MAX && dis[nr][nc] > dist + 1) {
                    vis[nr][nc] = 1;
                    dis[nr][nc] = 1 + dist;
                    pq.push({dis[nr][nc], {nr, nc}});
                }
            }
        }

        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (vis[i][j]) grid[i][j] = dis[i][j];
            }
        }
    }
};
