#define mod 1000000007
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        vector<int>left(n,-1),right(n,n);
        stack<int>s;
        for(int i=0;i<n;i++){
            while(!s.empty() && arr[s.top()]>=arr[i]){
                s.pop();
            }
            if(!s.empty()){
            left[i]=s.top();
            }

            s.push(i);
        }
        stack<int>st;
        for(int i=n-1;i>=0;i--){
             while(!st.empty() && arr[st.top()]>arr[i]){
                st.pop();
            }
            if(!st.empty()){
                right[i]=st.top();
            }
            st.push(i);
        }
        long long int ans=0;
        for(int i=0;i<n;i++){
            long long int c= ((i-left[i])*(right[i]-i) )% mod;
            ans=(ans+(c*arr[i])%mod)%mod;
        }
        return (int)ans;
    }
    
};