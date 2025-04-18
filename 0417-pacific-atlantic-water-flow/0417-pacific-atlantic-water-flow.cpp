class Solution {
public:
    void bfs(int n, int m, vector<vector<bool>>& vis, queue<pair<int,int>>& q, vector<vector<int>>& mat) {
        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};
        
        while (!q.empty()) {
            auto [currx, curry] = q.front();
            q.pop();
            
            for (int i = 0; i < 4; i++) {
                int nx = currx + dx[i];
                int ny = curry + dy[i];

                if (nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny] && mat[nx][ny] >= mat[currx][curry]) {
                    q.push({nx, ny});
                    vis[nx][ny] = true;
                }
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<bool>> vis1(n, vector<bool>(m, false)), vis2(n, vector<bool>(m, false));
        queue<pair<int, int>> q1, q2;

        // Pacific Border (Top Row & Left Column)
        for (int i = 0; i < m; i++) q1.push({0, i}), vis1[0][i] = true;
        for (int i = 0; i < n; i++) q1.push({i, 0}), vis1[i][0] = true;

        // Atlantic Border (Bottom Row & Right Column)
        for (int i = 0; i < m; i++) q2.push({n-1, i}), vis2[n-1][i] = true;
        for (int i = 0; i < n; i++) q2.push({i, m-1}), vis2[i][m-1] = true;

        bfs(n, m, vis1, q1, mat);
        bfs(n, m, vis2, q2, mat);

        vector<vector<int>> ans;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (vis1[i][j] && vis2[i][j])
                    ans.push_back({i, j});

        return ans;
    }
};