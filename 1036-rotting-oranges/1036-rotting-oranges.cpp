class Solution {
public:
    int bfs(queue<pair<int, int>>& q, vector<vector<int>>& adj,
            vector<vector<int>>& visited) {
        int m = adj.size(), n = adj[0].size();
        int ans = 0;

        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        while (!q.empty()) {
            int size = q.size();
            bool rotted = false;

            for (int k = 0; k < size; k++) {
                auto [row, col] = q.front();
                q.pop();

                for (auto [dx, dy] : directions) {
                    int newRow = row + dx;
                    int newCol = col + dy;

                    if (newRow >= 0 && newRow < m && newCol >= 0 &&
                        newCol < n && adj[newRow][newCol] == 1 &&
                        visited[newRow][newCol] == -1) {
                        visited[newRow][newCol] = 1;
                        adj[newRow][newCol] = 2;
                        q.push({newRow, newCol});
                        rotted = true;
                    }
                }
            }

            if (rotted) {
                ans++;
            }
        }

        return ans;
    }

    int orangesRotting(vector<vector<int>>& adj) {
        int m = adj.size(), n = adj[0].size();
        vector<vector<int>> visited(m, vector<int>(n, -1));
        queue<pair<int, int>> q;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (adj[i][j] == 2) {
                    q.push({i, j});
                    visited[i][j] = 1;
                }
            }
        }

        int ans = bfs(q, adj, visited);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (adj[i][j] == 1) {
                    return -1;
                }
            }
        }

        return ans;
    }
};
