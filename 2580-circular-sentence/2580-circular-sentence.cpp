class Solution {
public:
    bool isCircularSentence(string sentence) {
        int n=sentence.size();

        if(sentence[0]!=sentence[n-1]){return false;}
        for(int i=0;i<n;i++){

            char temp=sentence[i];
            while(i<n&&sentence[i]!=' '){
                temp=sentence[i];
                i++;
            }
            if(i+1<n){
                if(temp!=sentence[i+1]){return false;} 
            }

        }
        return true;
    }
};