class Solution {
public:
    bool valid(int row, int col, int i, int j) {
        if (i >= row || j >= col || i < 0 || j < 0)
            return false;
        return true;
    }
    int findMaxFish(vector<vector<int>>& grid) {
        vector<vector<int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        int m = grid.size(), n = grid[0].size();
        int ans = 0;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (!visited[i][j] && grid[i][j]>0) {
                 int maxi = 0;

                    queue<pair<int, int>> q;
                    q.push({i, j});
                    visited[i][j] = true;
                    while (!q.empty()) {
                        auto node = q.front();
                        int row = node.first;
                        int col = node.second;
                        // cout << row << " " << col << endl;
                        maxi+=  grid[row][col];
                        // cout << maxi << endl;
                        q.pop();
                        for (int k = 0; k < 4; k++) {
                            int newr = row + dirs[k][0];
                            int newc = col + dirs[k][1];
                            if (valid(m, n, newr, newc) &&!visited[newr][newc] && grid[newr][newc] > 0) {
                                visited[newr][newc] = true;
                                q.push({newr, newc});
                            }
                        }
                    }
                 ans = max(ans, maxi);
                   
                }
                
            }
        }
        return ans;
    }
};