class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int maxi=0;
        int ans=0;
        int n=values.size();
        for(int i=0;i<n;i++){
            ans=max(ans,maxi+values[i]-i);
            maxi=max(maxi,values[i]+i);
        }
        return ans;
    }
};
