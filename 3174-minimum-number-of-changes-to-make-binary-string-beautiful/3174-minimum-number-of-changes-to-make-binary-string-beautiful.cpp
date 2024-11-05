class Solution {
public:
    int minChanges(string s) {
        int cnt=0;
        char curr='x';
        int ans=0;
        int n=s.size();
        for(int i=0;i<n;i++){
           if(s[i]==curr){
            cnt++;
            continue;
           }
           if(cnt%2==0){
            cnt=1;
            curr=s[i];
           }
           else{
            cnt=0;
            ans++;
           }
        }
        return ans;
    }
};