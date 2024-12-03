class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans;
        int n=s.size();
        int z=spaces.size();
        int j=0;
        for(int i=0;i<n;i++){
            if(j<z && i==spaces[j]){
                ans+=" ";
                j++;
            }
            ans+=s[i];
        }
        return ans;
    }
};