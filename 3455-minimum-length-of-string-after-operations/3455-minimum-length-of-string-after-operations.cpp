class Solution {
public:
    int minimumLength(string s) {
      
        vector<int>cnt(26);
        for(char c:s) cnt[c-'a']++;
        int res = 0;
        for(int i=0;i<26;i++)
        {   if(cnt[i]!=0){
            if(cnt[i]%2==1){res +=  1;} 
            else{res += 2;}
        }
        }
        return res;
    }
};