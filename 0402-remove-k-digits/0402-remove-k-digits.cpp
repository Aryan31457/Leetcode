class Solution {
public:
    string removeKdigits(string num, int k) {
       string ans;
       stack<int>st;
       int n=num.size(); 
       for(int i=0;i<n;i++){

        while(!st.empty() && st.top()>(num[i]-'0') && k>0){
            st.pop();
            k--;
        }
        st.push(num[i]-'0');
       }

       while(k>0 && !st.empty()){
        st.pop();
        k--;
       }

       while(!st.empty()){
        int topi=st.top();
        ans=to_string(topi)+ans;
        st.pop();
       }
        int i=0;
       while(i<n && ans[i]=='0'){
        i++;
       }
       string result;
       n=ans.size();
       while(i<n){
        result+=ans[i];
        i++;
       }
       if(result.size()==0){
        result+='0';
       }
       return result; 
    }
};