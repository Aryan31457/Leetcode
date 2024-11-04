class Solution {
public:
    int compress(vector<char>& chars) {
        int cnt=0;
        int n=chars.size();
        char prev=chars[0];
        vector<char>ans;
        for(int i=0;i<n;i++){

            if(chars[i]==prev){
                cnt++;
            }

            else{
                ans.push_back(prev);
                if(cnt>1){
                string temp=to_string(cnt);
               
               for(int j=0;j<temp.size();j++){
                    ans.push_back(temp[j]);
               }
            }
            
                prev=chars[i];
                cnt=1;
            }
        }
               
                    ans.push_back(prev);

                 if(cnt>1){
                string temp=to_string(cnt);
               
               for(int j=0;j<temp.size();j++){
                    ans.push_back(temp[j]);
               }
                }
                
        for(int i=0;i<ans.size();i++){
            chars[i]=ans[i];
        }
        return ans.size();
    }
};