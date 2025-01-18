class Solution {
public:
    vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    int minCost(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<int>> dp(rows, vector<int>(cols, INT_MAX));
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        dp[0][0] = 0;
        pq.push({0, 0, 0});

        while (!pq.empty()) {
            auto [cost, row, col] = pq.top();
            pq.pop();

            for (int d = 0; d < 4; d++) {
                int newRow = row + dirs[d][0];
                int newCol = col + dirs[d][1];
                int newCost = (grid[row][col] != (d + 1)) ? 1 : 0;

                if (isValid(newRow, newCol, rows, cols) && dp[row][col] + newCost < dp[newRow][newCol]) {
                    dp[newRow][newCol] = dp[row][col] + newCost;
                    pq.push({dp[newRow][newCol], newRow, newCol});
                }
            }
        }

        return dp[rows - 1][cols - 1];
    }

private:
    bool isValid(int row, int col, int rows, int cols) {
        return row >= 0 && row < rows && col >= 0 && col < cols;
    }
};
