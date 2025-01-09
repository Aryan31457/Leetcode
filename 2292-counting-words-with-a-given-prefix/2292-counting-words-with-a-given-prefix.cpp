class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int ans=0;
        int n=words.size();
        int l=pref.length();
        for(int i=0;i<n;i++){
            int x=words[i].size();
            if(x>=l){
                if(words[i].substr(0,l)==pref)ans++;
            }
        }
        return ans;
    }
};