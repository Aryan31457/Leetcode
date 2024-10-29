#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int solve(vector<vector<int>>& grid, vector<vector<int>>& dp, int row, int col) {
        if (dp[row][col] != -1) return dp[row][col];
        
        int maxi = 0;
        
        if (row > 0 && col + 1 < grid[0].size() && grid[row][col] < grid[row - 1][col + 1]) {
            maxi = max(maxi, 1 + solve(grid, dp, row - 1, col + 1));
        }
        if (col + 1 < grid[0].size() && grid[row][col] < grid[row][col + 1]) {
            maxi = max(maxi, 1 + solve(grid, dp, row, col + 1));
        }
        if (row + 1 < grid.size() && col + 1 < grid[0].size() && grid[row][col] < grid[row + 1][col + 1]) {
            maxi = max(maxi, 1 + solve(grid, dp, row + 1, col + 1));
        }

        return dp[row][col] = maxi;
    }

    int maxMoves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        int ans = 0;

        for (int row = 0; row < m; ++row) {
            ans = max(ans, solve(grid, dp, row, 0));
        }
        
        return ans;
    }
};
