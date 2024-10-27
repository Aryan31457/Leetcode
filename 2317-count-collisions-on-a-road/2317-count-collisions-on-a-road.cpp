class Solution {
public:
    int countCollisions(string arr) {
        stack<char>st;
        int n=arr.size();
        int ans=0;
        int right=0;
        st.push(arr[0]);
        for(int i=1;i<n;i++){
            if(arr[i]=='L' && st.top()=='R'){
                ans+=2+right;
                st.push('S');
                right=0;
            }
            else if(st.top()=='R'&& arr[i]=='S'){
                ans+=1+right;
                st.push('S');
                right=0;
            }
            else if(st.top()=='S'&& arr[i]=='L'){
                ans+=1;
                st.push('S');
                right=0;
            }
            else{
                if(arr[i]=='R'&&st.top()=='R'){
                    right++;
                }
                st.push(arr[i]);
            }
            
        }
        return ans;
    }
};