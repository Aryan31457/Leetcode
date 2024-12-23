class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int ans=0;
        int i=0,j=0;
        int n=nums.size();
        while(i<n){
            while(j<i && nums[i]-nums[j]>2*k){
                j++;
            }
            ans=max(i-j+1,ans);
            i++;
        }
        return ans;
    }
};