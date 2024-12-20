class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.length();
        stack<char> st;
        for(int i = 0; i < n; i++){
            int ch = num[i] - '0';
            while(k > 0 && !st.empty() && (st.top() - '0') > ch){
                k--;
                st.pop();
            }

            st.push(num[i]);
        }
        while(k--) st.pop();

        string ans = "";
        while(!st.empty()){
             ans += st.top();
             st.pop();
        }
        reverse(ans.begin(), ans.end());
        int i = 0;
        for(; i < ans.length(); i++){
            if(ans[i] != '0') {break;}
        }

        if(ans.size()-i == 0){ return "0";}
         return ans.substr(i);
    }
};