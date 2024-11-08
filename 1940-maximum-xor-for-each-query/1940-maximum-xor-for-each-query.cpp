class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        vector<int>mappi(21,0);
        int xori=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            xori^=nums[i];
        }
        int maxi=pow(2,maximumBit)-1;
        int j=nums.size()-1;
        vector<int>ans(n,0);
        for(int i=0;i<n;i++){
            ans[i]=maxi^xori;
            xori^=nums[j];
            j--;
        }
        return ans;
        
    }
};