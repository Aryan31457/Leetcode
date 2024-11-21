class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans=0;
        int cnt=0;
        int j=0;
        int n=s.size();
        unordered_map<int,int>mappi;
        for(int i=0;i<n;i++){
            mappi[s[i]-'a']++;
            cnt++;
            while (j<i && mappi[s[i]-'a']>1){
                mappi[s[j]-'a']--;
                cnt--;
                j++;
            }
            ans=max(ans,cnt);
        }
        return ans;
    }
};