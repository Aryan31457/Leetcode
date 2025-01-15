class Solution {
    int solve(int index,int operation,vector<int>&prices, vector<vector<int>>&dp,int k){
        if(index==prices.size()){return 0;}
        if(operation==k){return 0;}
        if(dp[index][operation]!=-1){return dp[index][operation];}
        int profit=0;
        if(operation%2==0){
            int buy=(-prices[index]+solve(index+1,operation+1,prices,dp,k));
            int skip=0+solve(index+1,operation,prices,dp,k);
            profit+=max(buy,skip);
        }
        else{
            int sell=prices[index]+solve(index+1,operation+1,prices,dp,k);
            int skip=0+solve(index+1,operation,prices,dp,k);
            profit+=max(sell,skip);
        }
       return  dp[index][operation]=profit;
       
    }
public:
    int maxProfit(vector<int>& prices) {
    int k=2;
    vector<vector<int>>dp(prices.size()+1,vector<int>(2*k+1,-1));
     return solve(0,0,prices,dp,2*k);
    }
};