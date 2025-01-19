class Solution {
public:
    int subarraySum(vector<int>& nums) {
        vector<int>prefix(nums.size(),0);
        int sumi=0;
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++){
            prefix[i]=sumi;
            sumi+=nums[i];
        }
        for(int i=0;i<n;i++){
            int start=max(0, i - nums[i]);
            ans+=(prefix[i]-prefix[start])+nums[i];
        }
        return ans;
    }
};