class Solution {
public:
    string makeFancyString(string s) {
        int cnt=0;
        char temp='$';
        string ans="";
        for(int i=0;i<s.size();i++){
            if(s[i]!=temp){
                ans+=s[i];
                cnt=1;
                temp=s[i];
            }
            else if(s[i]==temp){
                if(cnt<2){
                cnt++;
                ans+=temp;
                }
                else{
                    continue;
                }
            }
        }
        return ans;
    }
};