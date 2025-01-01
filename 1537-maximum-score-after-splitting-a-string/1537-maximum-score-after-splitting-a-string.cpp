class Solution {
public:
    int maxScore(string s) {

        int n=s.size();

        int cnt1=0,cnt0=0;
        for(int i=0;i<n;i++){
            if(s[i]=='1')cnt1++; 
        }

        int ans=0;
         for(int i=0;i<n-1;i++){
           if(s[i]=='0')cnt0++;
           else cnt1--;

            int temp=cnt1+cnt0;
            ans=max(ans,temp);

        }

        return ans;

    }
};