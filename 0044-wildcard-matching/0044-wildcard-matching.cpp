class Solution {
    bool solve(string &s,string &p,int i,int j,vector<vector<int>>&dp){
        if(j<0&&i<0){return true;}
        if(i>=0&&j<0){return false;}
        if(i<0&&j>=0){
            for(int k=0;k<=j;k++){
                if(p[k]!='*'){return false;}
            }
            return true;
        }
        if(dp[i][j]!=-1){return dp[i][j];}
        if(p[j]=='?'||s[i]==p[j]){return dp[i][j]= solve(s,p,i-1,j-1,dp);}
        else if(p[j]=='*')
        {
        return dp[i][j]=solve(s,p,i-1,j,dp)||solve(s,p,i,j-1,dp);
        }
        else{
            return false;
        }
    }
public:
    bool isMatch(string s, string p) {
        vector<vector<int>>dp(s.size()+1,vector<int>(p.size()+1,-1));
        return solve(s,p,s.size()-1,p.size()-1,dp);
    }
};