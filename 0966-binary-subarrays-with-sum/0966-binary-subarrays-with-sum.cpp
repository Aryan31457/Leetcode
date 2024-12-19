class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int>mappi;
        int ans=0;
        int sum=0;
        int n=nums.size();
        mappi[0]=1;
        for(int i=0;i<n;i++){
            sum+=nums[i];
           
            ans+=mappi[sum-goal];
            
            mappi[sum]++;
        }
        return ans;
     }
};