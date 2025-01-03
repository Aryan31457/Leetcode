class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long sumi=0;
        for(auto i:nums)sumi+=i;
        int n=nums.size();
        long long sum=0;
        int ans=0;
        for(int i=0;i<n-1;i++){
            sum+=nums[i];
            sumi-=nums[i];
            if(sum>=sumi){
                ans++;
            }
        }
    return ans;
    }
};