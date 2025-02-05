class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        
        int flag=-1;
        int n=s1.size();
        for(int i=0;i<n;i++){
            if(s1[i]!=s2[i]){
                // cout<<i<<" ";
                if(flag==-2)return false;
                // cout<<i<<" "<<flag<<endl;
                if(flag==-1){
                flag=i;
                }
                else{
                    // cout<<s1[i]<<" "<<s2[flag]<<" "<< s2[i]<<" "<<s1[flag]<<endl;
                    if(s1[i]!=s2[flag] || s2[i]!=s1[flag]){
                        return false;
                    }
                    else{
                        // cout<<"j";
                        flag=-2;
                    }
                }
            }
        }
        if(flag==-1||flag==-2){
            return true;
        }
        return false;
    }
};