      class Solution {
    int solve(vector<int>&coins,int index,int amount,vector<vector<int>>&dp){
        if(amount==0){
            return 1;
        } 
        if(index>=coins.size()){return 0;}
        if(amount<0){return 0;}
        if(dp[index][amount]!=-1){return dp[index][amount];}
        int exc=solve(coins,index+1,amount,dp);
        int inc=0;
        if(amount>=coins[index]){
        inc=solve(coins,index,amount-coins[index],dp);
        }
        return dp[index][amount]=exc+inc;
    }
public:
    int change( int amount,vector<int>& coins) {
      
        vector<vector<int>>dp(coins.size(),vector<int>(amount+1,-1));
        int ans= solve(coins,0,amount,dp);
        return ans; 
    }
};
