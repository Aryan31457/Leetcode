class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int i=0,j=0;
        int n=sentence.size(),y=searchWord.size();
       unordered_map<string,int>mappi;
       int cnt=1;
       for(int i=0;i<n;i++){
        string temp;
        while(i<n && sentence[i]!=' '){
            temp+=sentence[i];
            if(temp==searchWord){
                return cnt;
            }
            i++;
        }
        mappi[temp]=cnt;
        cnt++;
       }
       for(auto i:mappi){
        cout<<i.first<<" "<<i.second<<endl;
       }
        return -1;
      
    }
};