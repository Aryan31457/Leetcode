class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        long long int sumi=0;
        for(auto i:shifts)sumi+=i;
        string ans;
        for(int i=0;i<s.size();i++){

            long long int x='a'+((s[i]-'a')+sumi)%26;
            ans+=string(1,x);
            sumi-=shifts[i];
        }
        return ans;
    }
};