class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i=0,j=0,ans=0,n=nums.size();
        while(i<n){
            if(nums[i]==0){
                k--;
            }
            while(j<i && k<0){
            if(nums[j]==0){
                k++;
            }
                j++;
            }
            if(k>=0){
            ans=max(i-j+1,ans);
            }
            i++;
        }
        return ans;
    }
};