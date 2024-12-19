class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int ans=0;
        int odd=0;
        int n=nums.size();
        int i=0,j=0;
        while(i<n){
            if(nums[i]%2==1){
                odd++;
            }
            if(odd==k){
                int temp=i+1;
                int cnt=1;
                while(temp<n && nums[temp]%2==0){
                    cnt++;
                    temp++;
                }
                int chk=0;
                while(j<n && odd==k){
                    chk++;
                    if(nums[j]%2==1){
                        odd--;
                    }
                    j++;
                }
                ans+=cnt*chk;
            }
            i++;
        }
        return ans;
    }
};