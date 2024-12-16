class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans;
        stack<char>st;
        int open=0,close=0;
        int n=s.size();
        int i=n-1;
        while(i>=0){
            if(s[i]==')'){close++;}
            if(s[i]=='('){open++;}

            if(open==close && open!=0){
                string temp="";
                while(st.size()>1){
                    temp+=st.top();
                    st.pop();
                }
                st.pop();
                ans=temp+ans;
                open=0;
                close=0;
            }
            else{
                st.push(s[i]);
            }
            i--;
        }
        return ans;
    }
};