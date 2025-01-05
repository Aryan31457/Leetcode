class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        string ans;
        long long sum=0;
        for(int i=shifts.size()-1;i>=0;i--){
            sum=sum+shifts[i];
            ans+='a'+(s[i]-'a'+sum)%26;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};