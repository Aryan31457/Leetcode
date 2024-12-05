class Solution {
public:
    bool canChange(string start, string target) {
        int m=target.size(),n=start.size();
        int i=0,j=0;
        while(i<m || j<n ){

            while(i<m && target[i]=='_'){
                i++;
            }
            while(j<n && start[j]=='_'){
                j++;
            }
            if(i==m && j==n){
                return true;
            }
            if(i==m || j==n || start[j]!=target[i]){
                return false;
            }

                if(start[j]=='L'){
                if(j<i){
                    return false;
                }
                else{
                    i++;
                    j++;
                }
            }
            else{
                if(j>i){
                    return false;
                }
                else{
                    i++;
                    j++;
                }
            }
            
        }
        if(i>=m && j>=n){
        return true;
        }
        return false;
    }
};