class Solution {
public:
   int solve(vector<int>&coins,int index,int amount,vector<vector<int>>&dp){
        if(amount==0){
            return 0;
        } 
        if(index>=coins.size()){return 1e9;}
        if(amount<0){return 1e9;}
        if(dp[index][amount]!=-1){return dp[index][amount];}
        //exclude
        int exc=solve(coins,index+1,amount,dp);
        int inc=1e9;
        if(amount>=coins[index]){
        inc=1+solve(coins,index,amount-coins[index],dp);
        }
        return dp[index][amount]=min(exc,inc);

    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>>dp(coins.size(),vector<int>(amount+1,-1));
        int ans= solve(coins,0,amount,dp);
        return ans==1e9? -1:ans;  
    }
};