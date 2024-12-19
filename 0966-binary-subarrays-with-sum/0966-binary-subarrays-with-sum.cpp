class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
      int i=0,j=0;
      int n=nums.size();
      int sum=0;
      int ans=0;
       if (goal == 0) {
            int zeroCount = 0;
            for (int num : nums) {
                if (num == 0) {
                    zeroCount++;
                } else {
                    ans += zeroCount * (zeroCount + 1) / 2;
                    zeroCount = 0;
                }
            }
            ans += zeroCount * (zeroCount + 1) / 2;
        }
        else{
      while(i<n){
       
        sum+=nums[i];
        if(sum==goal){
            int cnt=1;
            int temp=i+1;
            while(temp<n && nums[temp]==0){
                temp++;
                cnt++;
            }
        
        int chk=0;
        while(j<=i&&sum==goal){
            sum-=nums[j];
            j++;
            chk++;
        }

        ans+=chk*cnt;
        }
        i++;
      }  
        }
     
      return ans;
    }
};