class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n=nums.size();
        if(n==1||k==1)return nums;
        int ans=0;
        int i=1,j=1;
        int cnt=1;
        int prev=nums[0];
        vector<int>result;
        while(i<n){
            if(nums[i]==prev+1){
                cnt++;
            }
            if(i==k-1){
                if(cnt==k){
                    result.push_back(nums[i]);
                }
                else{
                    result.push_back(-1);
                }
                if(nums[j]==nums[j-1]+1){
                    cnt--;
                }
            }
            if(i-j+1==k){
                // cout<<j<<" "<<i<<" "<<cnt<<endl;
                if(cnt==k){
                    result.push_back(nums[i]);
                }
                else{
                    result.push_back(-1);
                }
                j++;
                if(nums[j]==nums[j-1]+1){
                    cnt--;
                }
            }
            prev=nums[i];
            i++;
        }
        return result;
    }
};