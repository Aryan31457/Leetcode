class Solution {
public:
//Dekh apan n-1 ko badha skte hai is equivalent to kisi ek ko 1 se decrease
    int minMoves(vector<int>& nums) {
        int mini=INT_MAX;
        int n=nums.size();
        for(int i=0;i<n;i++){
            mini=min(mini,nums[i]);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=(nums[i]-mini);
        }
        return ans;
    }
};