class Solution {
public:
    string removeKdigits(string num, int k) {
       string ans;
       stack<char>st;
       int n=num.size(); 
       for(int i=0;i<n;i++){

        while(!st.empty() && (st.top()-'0')>(num[i]-'0') && k>0){
            st.pop();
            k--;
        }
        st.push(num[i]);
       }

       while(k>0 && !st.empty()){
        st.pop();
        k--;
       }

       while(!st.empty()){
        ans+=st.top();
        st.pop();
       }
       reverse(ans.begin(),ans.end());
       int i=0;
       while(i<n && ans[i]=='0'){
        i++;
       }
       n=ans.size();
       if(n-i==0){
        return "0";
       }
       return ans.substr(i); 
    }
};