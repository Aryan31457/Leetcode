class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int ans=0;
        int odd=0;
        int count=0;
        int n=nums.size();
        int i=0,j=0;
        while(i<n){
            if(nums[i]%2==1){
                odd++;
                count=0;
            }
                while(j<n && odd==k){
                    if(nums[j]%2==1){
                        odd--;
                    }
                    count++;
                    j++;
                   
                }
                 ans+=count;
           
            i++;
        }
        return ans;
    }
};