class Solution {
public:
    string compressedString(string chars) {
         int cnt=0;
        int n=chars.size();
        char prev=chars[0];
        string ans;
        for(int i=0;i<n;i++){

            if(chars[i]==prev && cnt<9){
                cnt++;
            }

            else{
               
                string temp=to_string(cnt);
                ans+=temp;
                 ans+=prev;
            
            
                prev=chars[i];
                cnt=1;
            }
            }
        
               
            string temp=to_string(cnt);
            ans+=temp;
            ans+=prev;


        return ans;
    }
};