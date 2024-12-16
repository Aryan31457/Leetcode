class Solution {
public:
    int beautySum(string s) {
       int ans=0;
       int n=s.size();
       for(int i=0;i<n;i++){
       
        vector<int>count(26,0);
        for(int j=i;j<n;j++){
            int mini=INT_MAX,maxi=INT_MIN;
            count[s[j]-'a']++;
            for(int k=0;k<26;k++){
            if(count[k]>0){
            mini=min(mini, count[k]);
            maxi=max(maxi, count[k]);
            }
            }
            ans+=maxi-mini;
        }
       } 
       return ans;
    }
};