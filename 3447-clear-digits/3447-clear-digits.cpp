class Solution {
public:
    string clearDigits(string s) {
        string ans;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(isalpha(s[i])){
                ans+=s[i];
            }
            else{
                if(ans.size()>0){
                ans.erase(ans.size()-1,1);
                }
            }
        }
        return ans;
    }
};