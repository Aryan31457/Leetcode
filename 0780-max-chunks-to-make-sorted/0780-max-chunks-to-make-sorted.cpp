class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int ans=0;
        int n=arr.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=arr[i]-i;
            if(sum==0){
                ans++;
            }
        }
        return ans;
    }
};