class Solution {
public:
    int maxScore(string s) {

        int n=s.size();

        vector<int>zero(n,0),one(n,0);
        int cnt1=0,cnt0=0;
        for(int i=0;i<n;i++){

            if(s[i]=='0')cnt0++;
            if(s[n-i-1]=='1')cnt1++;

            zero[i]=cnt0;
            one[n-i-1]=cnt1;

           
        }

        int ans=0;
         for(int i=0;i<n-1;i++){
           

            int temp=zero[i]+one[i+1];
            ans=max(ans,temp);

        }

        return ans;

    }
};