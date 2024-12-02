class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int i=0,j=0;
        int n=sentence.size(),y=searchWord.size();
       int cnt=1;
       for(int i=0;i<n;i++){
        string temp;
        while(i<n && sentence[i]!=' '){
            temp+=sentence[i];
            if(temp.size()==y && temp==searchWord){
                return cnt;
            }
            i++;
        }
        cnt++;
       }
      
        return -1;
      
    }
};