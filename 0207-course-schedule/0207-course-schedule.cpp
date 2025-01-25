class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<int>outdegree(n);
        set<int>ans;
        queue<int>q;
        unordered_map<int,vector<int>>adj;
        int c=0;
        for(int i=0;i<pre.size();i++){  
                adj[pre[i][0]].push_back(pre[i][1]);
                outdegree[pre[i][1]]++;
        } 

        for(int i=0;i<n;i++){
            if(outdegree[i]==0){
                q.push(i);
            }
        }

        while(!q.empty()){

            int node=q.front();
            q.pop();
            c++;
            for(auto i:adj[node]){
                outdegree[i]--;
                if(outdegree[i]==0){
                    q.push(i);
                }
            }
        }
        cout<<c;
        return c==n;
    }
};