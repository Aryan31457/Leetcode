class Solution {
public:
    bool canBeValid(string s, string l) {
       int n=s.size();
        if(n%2==1)return false;
        int balance=0;
        for(int i=0;i<n;i++){
            if(s[i]=='(' || l[i]=='0')balance++;
            else balance--;

            if(balance<0)return false;
        }
        balance=0;
        for(int i=n-1;i>=0;i--){
            if(s[i]==')' || l[i]=='0')balance++;
            else balance--;

            if(balance<0)return false;
        }

       
       return true;
    }
};