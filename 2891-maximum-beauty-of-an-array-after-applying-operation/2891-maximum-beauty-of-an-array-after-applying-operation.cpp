class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int ans=0;
        int maxi=0;
        int n=nums.size();
    
        for(int i=0;i<n;i++){
            maxi=max(maxi,nums[i]);
        }

        vector<int>mappi(maxi+1,0);
        for(int i=0;i<n;i++){
            int start=nums[i];
            mappi[(max(0,start-k))]++;

            if(start+k+1<=maxi){
                mappi[start+k+1]--;
            }
        }
        int sum=0;
        for(int i=0;i<maxi+1;i++){
            sum+=mappi[i];
            ans=max(ans,sum);
            
        }
        return ans;
    }
};