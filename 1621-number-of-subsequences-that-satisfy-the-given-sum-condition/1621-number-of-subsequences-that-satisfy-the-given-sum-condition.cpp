#define MOD 1000000007
class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int> pow(n);
        pow[0]=1;
        for(int i=1;i<n;i++)pow[i]=(pow[i-1]*2)%MOD;
        int i=0,j=n-1;
        int ans=0;
        while(i<=j){
            int sum=nums[i]+nums[j];
            if(sum<=target){
                ans=(ans+pow[(j-i)])% MOD;
                i++;
            }
            else{
                j--;
            }
        }
        return ans;
    }
};