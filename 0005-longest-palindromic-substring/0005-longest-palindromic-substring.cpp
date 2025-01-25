class Solution {
public:

    string solve(string s, int i,int j){
        int n=s.size();
        if(n<=1){
            return s;
        }
        while(i>=0 && j<n && s[i]==s[j]){
            i--;
            j++;
        }
        return s.substr(i+1,j-i-1);
    }
    string longestPalindrome(string s) {
        string ans=s.substr(0,1);
        int n=s.size();
        for(int i=0;i<n-1;i++){
        string odd=solve(s,i,i);
        string even=solve(s,i,i+1);


        if(odd.size()>ans.size())ans=odd;
        if(even.size()>ans.size())ans=even;

        }
        return ans;

    }
};