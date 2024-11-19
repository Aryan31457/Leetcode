class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
      long long ans=0;
      int i=0,j=0;
      unordered_map<int,int>mappi;
      int n=nums.size();
      long long sum=0;
      while(j<n){
        sum+=nums[j];
        mappi[nums[j]]++;
         
        while(i<j && mappi[nums[j]]>1){
                mappi[nums[i]]--;
                sum-=nums[i];
                i++;
        }
        if(j-i+1==k){
            ans=max(ans,sum);
            sum-=nums[i];
            mappi[nums[i]]--;
            i++;
        }
      
        j++;
      }
      return ans;
    }
};