class Solution {
public:
    int solve(int index,int buy,vector<int>&prices, vector<vector<int>>&dp,int fee){
        if(index>=prices.size()){return 0;}
        if(dp[index][buy]!=-1){return dp[index][buy];}
        int profit=0;
        if(buy){
            int buy=(-prices[index]+solve(index+1,0,prices,dp,fee));
            int skip=0+solve(index+1,1,prices,dp,fee);
            profit=max(buy,skip);
        }
        else{
            int sell=prices[index]-fee+solve(index+1,1,prices,dp,fee);
            int skip=0+solve(index+1,0,prices,dp,fee);
            profit=max(sell,skip);
        }
        return dp[index][buy]=profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>>dp(prices.size()+1,vector<int>(2,-1));
        return solve(0,1,prices,dp,fee);
    }
};