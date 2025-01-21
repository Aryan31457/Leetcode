class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n=grid[0].size();
        vector<long long>pre(n),suf(n);
        long long psum=0,ssum=0;
        for(int i=0;i<n;i++){
            psum+=grid[0][i];
            ssum+=grid[1][n-i-1];

            pre[i]=psum;
            suf[n-i-1]=ssum;
        }

        // int idx=-1;
        // long long maxi=0;

        // for(int i=0;i<n;i++){
        //     // cout<<pre[i]<<" "<<suf[i]<<endl;
        //     long long sumi=pre[i]+suf[i];
        //     if(sumi>maxi){
        //      maxi=max(maxi,sumi);   
        //     }
        // }
        // cout<<maxi<<endl;
        long long ans=LLONG_MAX;
        for(int i=0;i<n;i++){
            // long long sumi=pre[i]+suf[i];
            // if(sumi==maxi){
               ans=min(max(psum-pre[i],ssum-suf[i]),ans);
            // }
        }
        return ans;


    }
};