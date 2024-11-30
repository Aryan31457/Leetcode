class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        string t=s;
        int maxi=0;
        int i_idx=0;
        reverse(t.begin(),t.end());
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(s[i]==t[j]){
                    dp[i+1][j+1]+=dp[i][j]+1;
                    if(dp[i+1][j+1]>maxi){
                        int start=i-dp[i+1][j+1]+1;
                        if(start==n-(j+1)){
                        maxi=dp[i+1][j+1];
                        i_idx=i;
                        }
                    }
                }
            }
        }
        string ans=s.substr(i_idx-maxi+1,maxi);
        // cout<<s.substr(i_idx-maxi+1,maxi);
        return ans;

    }
};