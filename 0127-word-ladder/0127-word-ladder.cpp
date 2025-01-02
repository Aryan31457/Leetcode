class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        bool flag=false;
        for(int i=0;i<wordList.size();i++){
            if(wordList[i]==endWord){
            flag=true;
            break;}
        }
        if(!flag)return 0;


        unordered_map<string ,vector<string>>mappi;
        int n=wordList.size();
        for(int i=0;i<n;i++){   
            string temp=wordList[i];
            int x=temp.size();
            for(int j=0;j<x;j++){
                string pattern=temp;
                pattern[j]='*';
                mappi[pattern].push_back(temp);
            }
        }

        queue<string> q;

        q.push(beginWord);

        unordered_map<string ,bool>visited;
        visited[beginWord]=true;
        int cnt=1;
        while(!q.empty()){
            int a=q.size();
            for(int i=0;i<a;i++){
            string temp=q.front();
            visited[temp]=true;

            if(temp==endWord){return cnt;}
            q.pop();
            int x=temp.size();
               for(int j=0;j<x;j++){
                string pattern=temp;
                pattern[j]='*';
                for(auto x:mappi[pattern]){
                    if(!visited[x]){
                        q.push(x);
                    }
                }
            }
            }
            cnt++;
        }
        return 0;
    }
};