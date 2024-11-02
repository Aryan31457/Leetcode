class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n=code.size();
        if(k==0){
            vector<int>ans(n,0);
            return ans;
        }
        if(k>0){
            vector<int>ans(n,0);
            int window=0;
            for(int i=1;i<=k;i++)window+=code[i%n];
            ans[0]=window;
            int cnt=1;
            for(int i=1;i<n;i++){
                window-=code[i];
                window+=code[(i+k)%n];
                ans[i]=window;
            }
            return ans;
        }
        else{
            vector<int>ans(n,0);
            int window=0;
            k=-k;
            for(int i=n-k;i<n;i++)window+=code[i];
            ans[0]=window;
            int cnt=1;
            for(int i=0;i<n;i++){
                ans[i]=window;
                window-=code[(i-k+n)%n];
                window+=code[i];  
            }
            return ans;
        }
    }
};