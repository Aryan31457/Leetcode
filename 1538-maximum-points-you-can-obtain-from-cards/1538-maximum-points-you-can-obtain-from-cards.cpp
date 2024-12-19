class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        vector<int>x;
        int n=cardPoints.size();
        if(k>n){return 0;}
        for(int i=0;i<k;i++){
            x.push_back(cardPoints[i]);
        }
        reverse(x.begin(),x.end());
        for(int i=n-1;i>=n-k;i--){
            x.push_back(cardPoints[i]);
        }
        int window=0;
        int ans=0;
        int i=0,j=0;
        while(i<k){
            window+=x[i];
            i++;
        }
        ans=window;
        n=x.size();
        while(i<n){
           window-=x[j];
           window+=x[i];
           ans=max(window,ans);
           i++;
           j++;
        }
        return ans;
    }
};