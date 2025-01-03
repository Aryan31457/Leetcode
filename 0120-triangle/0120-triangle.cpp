class Solution {
public:
  int solve(vector<vector<int>>& grid,int row,int col,vector<vector<int>>&dp){
        if(row==0 ){
            return grid[0][0];
        }
        int m=grid[row].size();
        if(row<0 || col<0 || col >= m)return INT_MAX;

        if(dp[row][col]!=-1){return dp[row][col];}

        int way1=solve(grid,row-1,col,dp);
        int way2=INT_MAX;
        if(col>0){way2=solve(grid,row-1,col-1,dp);}
        return dp[row][col]= grid[row][col]+ min(way1,way2);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int m=triangle.size(),n=triangle[m-1].size();
        vector<vector<int>>dp(m,vector<int>(m,-1));
        int ans=INT_MAX;
        for(int i=0;i<m;i++){
            ans=min(ans,solve(triangle,m-1,i,dp));
        }
        return ans;
    }
};