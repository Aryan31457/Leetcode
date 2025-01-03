class Solution {
public:
    int solve(int m,int n,int row,int col,  vector<vector<int>>&dp){
        if(row==m-1 && col==n-1){
            return 1;
        }
        if(row>m-1 || col>n-1)return 0;

        if(dp[row][col]!=-1){return dp[row][col];}

        return dp[row][col]= solve(m,n,row+1,col,dp)+ solve(m,n,row,col+1,dp);
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return solve(m,n,0,0,dp);
    }
};