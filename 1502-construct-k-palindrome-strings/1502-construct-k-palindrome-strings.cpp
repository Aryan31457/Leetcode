class Solution {
public:
    bool canConstruct(string s, int k) {
        int n=s.size();

        if(n<k)return false;
        if(n==k)return true;
        
        vector<int>cnt(26,0);
        for(auto i:s){
            cnt[i-'a']++;
        }
        int odd=0;
        for(int i=0;i<26;i++){
        if(cnt[i]&1==1)odd++;
        }
        if(odd<=k)return true;
        return false;
    }
};