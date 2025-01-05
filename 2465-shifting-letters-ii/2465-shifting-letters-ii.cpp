class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        vector<int>count(s.size(),0);
        int n=shifts.size();
        int l=s.size();
        for(int i=0;i<n;i++){
            int st=shifts[i][0];
            int e=shifts[i][1];
            int d=shifts[i][2];
            if(d){
            count[st]+=1;
            if(e+1<l){
            count[e+1]-=1;}
            }
            else{
            count[st]-=1;
            if(e+1<l){
            count[e+1]+=1;}
            }
        }
        string ans;
        int cnt=0;
        for(int i=0;i<count.size();i++){
            cnt+=count[i];
            int change=((s[i]-'a'+cnt)%26);
            if(change<0){
                change+=26;
            }
            ans+='a'+change;
        }
        return ans;
    }
};