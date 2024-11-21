class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i=0,j=0;
        int n=nums.size();
        int ans=0;
        vector<int>count(2,0);
        while(i<n){
            count[nums[i]]++;
            while(j<n && count[0]>k){
                count[nums[j]]--;
                j++;
            }
            ans=max(ans,i-j+1);
            i++;
        }
        return ans;
    }
};