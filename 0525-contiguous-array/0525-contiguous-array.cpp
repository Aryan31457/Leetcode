class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int>mappi;
        int n=nums.size();
        int ans=0;
        int sum=0;
        mappi[0]=-1;
        for(int i=0;i<n;i++){
            if(nums[i])sum+=1;
            else sum-=1;

            if(mappi.find(sum)!=mappi.end()){
                ans=max(ans,i-mappi[sum]);
            }
            else{
                mappi[sum]=i;
            }
        }
        return ans;
    }
};