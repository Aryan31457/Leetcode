class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& q) {
        vector<char>vowel={'a', 'e', 'i', 'o','u'};
        int n=words.size();
        vector<int>cnt(n);
        vector<bool>chk(n);
        int count=0;
        for(int i=0;i<n;i++){
            int x=words[i].size();

            bool front=false;
            for(int j=0;j<5;j++){
                if(words[i][0]==vowel[j]){
                    front=true;
                    break;
                }
            }
              bool last=false;
            for(int j=0;j<5;j++){
                if(words[i][x-1]==vowel[j]){
                    last=true;
                    break;
                }
            }

            if(front&&last){
                chk[i]=true;
                count++;
            }
            cnt[i]=count;
        }

        vector<int>ans;
        int que=q.size();
         for(int i=0;i<que;i++){
            int first=q[i][0],second=q[i][1];

            int num=cnt[second]-cnt[first];
            if(chk[first])num++;
            ans.push_back(num);
         }
         return ans;

    }
};