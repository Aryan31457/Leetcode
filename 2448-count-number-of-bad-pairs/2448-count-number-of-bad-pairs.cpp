class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        
        unordered_map<int,long long>mappi;
        long long ans=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int diff=i-nums[i];
            mappi[diff]++;
            int cnt=i+1;

            ans+=cnt-mappi[diff];
        }
        return ans;
    }
};