class Solution {
public:
    string clearDigits(string s) {
        string ans;
        int n=s.size();
        stack<char>temp;
        for(int i=0;i<n;i++){
            if(isalpha(s[i])){
                temp.push(s[i]);
            }
            else{
              if(!temp.empty()){
                temp.pop();
              }
            }
        }
        while(!temp.empty()){
            ans+=temp.top();
            temp.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};