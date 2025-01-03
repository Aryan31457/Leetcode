class Solution {
public:
 int solve(vector<vector<int>>& grid,int m,int n,int row,int col,  vector<vector<int>>&dp){
        if(row==m-1 && col==n-1){
            return 1;
        }
        if(row>m-1 || col>n-1)return 0;
        if(dp[row][col]!=-1){return dp[row][col];}
        if(grid[row][col]==1)return 0;


        return dp[row][col]= solve(grid,m,n,row+1,col,dp)+ solve(grid,m,n,row,col+1,dp);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        if(grid[m-1][n-1]==1 || grid[0][0]==1)return 0;
         vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return solve(grid,m,n,0,0,dp);
    }
};