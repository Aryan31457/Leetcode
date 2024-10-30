class Solution {
public:
    long long maximumSumOfHeights(vector<int>& heights) {
        int n=heights.size();
        long long ans=0;
       for(int i=0;i<n;i++){
        long long temp=heights[i];
        int mini=heights[i];
        for(int j=i-1;j>=0;j--){
            mini=min(heights[j],mini);
            temp+=mini;
        }

        mini=heights[i];
        for(int j=i+1;j<n;j++){
             mini=min(heights[j],mini);
            temp+=mini;
       } 
       ans=max(temp,ans);
    }
       return ans;
    }
};