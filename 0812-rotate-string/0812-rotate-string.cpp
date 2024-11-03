class Solution {
public:
    bool rotateString(string s, string goal) {
         int n=s.length();
         int m=goal.length();
         if(m!=n){return false;}
        s+=s;
        for(int i=0;i<n;i++){
            string temp=s.substr(i,m);
            cout<<temp<<" ";
            if(goal==temp){
                return true;
            }
        }
        return false;
    }
};