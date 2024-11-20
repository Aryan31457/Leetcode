class Solution {
public:
    int takeCharacters(string s, int k) {
       vector<int>count(3,0);
        int ans=0;
        int st=INT_MAX;
        int n=s.size();
        for(int i=0;i<n;i++){
            count[s[i]-'a']++;
        }
        if(count[0]<k||count[1]<k||count[2]<k){return -1;}
        
        vector<int>window(3,0);
        int j=0;
       for(int i=0;i<n;i++){
        window[s[i]-'a']++;
        while(j<=i && count[0]-window[0]<k||count[1]-window[1]<k||count[2]-window[2]<k){
            window[s[j]-'a']--;
            j++;
        }
        ans=max(ans,i-j+1);
       }
       return n-ans;
    }
};