class Solution {
public:
    int minInsertions(string text1) {
        string text2=text1;
        reverse(text2.begin(),text2.end());
         int n=text1.size(),m=text2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(text1[i]==text2[j]){
                    dp[i+1][j+1]=dp[i][j]+1;
                }
                else{
                    dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j]);
                }
            }
        }
        int matched=dp[n][m]; 
        if(matched==n)return 0;

        return n-matched;
    }
};