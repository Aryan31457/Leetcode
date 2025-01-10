class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string>ans;

        vector<int>mappi(26,0);

        for(int i=0;i<words2.size();i++){
            vector<int>cnt(26,0);
            for(int j=0;j<words2[i].size();j++){
                int w=words2[i][j]-'a';
                cnt[w]++;
                mappi[w]=max(mappi[w],cnt[w]);
            }
        }


        for(int i=0;i<words1.size();i++){

            vector<int>cnt(26,0);
            for(int j=0;j<words1[i].size();j++){
                int w=words1[i][j]-'a';
                cnt[w]++;
            }
            bool flag=true;
             for(int j=0;j<26;j++){
               if(cnt[j]<mappi[j]){
                flag=false;
                break;
               }    
            }
            if(flag)ans.push_back(words1[i]);

        }
        return ans;


    }
};