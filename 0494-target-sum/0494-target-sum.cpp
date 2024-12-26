class Solution {
public:
    void solve(vector<int>&nums,int idx,int target,int &ans){
        if(idx>=nums.size()){
            if(target==0){
                ans++;
            }
            return ;
        }

        solve(nums,idx+1,target+nums[idx],ans);
        solve(nums,idx+1,target-nums[idx],ans);

        return ;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int ans=0;

       solve(nums,0,target,ans);
       return ans;
    }
};