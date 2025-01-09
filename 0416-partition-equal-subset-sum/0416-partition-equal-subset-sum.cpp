class Solution {
public:
        bool solve(int idx,int target,vector<int>&arr,int sumi, vector<vector<int>>&dp){
        if(target==0)return true;
        
       
        
        if (idx>=arr.size())return false;
        
        if(dp[idx][target]!=-1)return dp[idx][target];
        
        bool way1=solve(idx+1,target,arr,sumi,dp);
        bool way2=false;
        if(arr[idx]<=target){
        way2=solve(idx+1,target-arr[idx],arr,sumi+arr[idx],dp);
        }
        return dp[idx][target]= way1||way2;
        
    }

    bool canPartition(vector<int>& arr) {
      int sum=0;
      for(auto i:arr)sum+=i;
      if(sum%2==1)return false;
      int target=sum/2;
    vector<vector<int>>dp(arr.size(),vector<int>(target+1,-1));
      return solve(0,target,arr,0,dp);  
    }
};