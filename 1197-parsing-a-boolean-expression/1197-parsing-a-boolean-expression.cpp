class Solution {
public:
    char solve(vector<char>&arr,char &op){
        char ans;
        if(op=='!'){
            if(arr[0]=='t')return 'f';
            return 't';
        }
        else if(op=='&'){
            bool flag=true;
            for(int i=0;i<arr.size();i++){
                if(arr[i]=='f')
                {
                flag=false;
                break;
                }
            }
            if(flag)return 't';
            return 'f';
        }
        else{
            bool flag=false;
            for(int i=0;i<arr.size();i++){
                if(arr[i]=='t')
                {
                flag=true;
                break;
                }
            }
            if(flag)return 't';
            return 'f';
        }
    }
    bool parseBoolExpr(string s) {
        stack<char>st;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]==',')continue;
            
            if(s[i]==')'){
                vector<char>values;
                while(st.top()!='('){
                    values.push_back(st.top());
                    st.pop();
                }
                st.pop();
                char op=st.top();
                st.pop();
                st.push(solve(values,op));
            }
            else{
                st.push(s[i]);
            }
        }
        if(st.top()=='t')return true;
        return false;
    }
};