class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
        int n=graph.size();
        vector<int>outdegree(n);
        set<int>ans;
        vector<int>visited(n);
        queue<int>q;
        for(int i=0;i<n;i++){
            outdegree[i]=graph[i].size();
            if(graph[i].size()==0){
                q.push(i);
                ans.insert(i);
                visited[i]=1;
            }
        }

        unordered_map<int,vector<int>>adj;

        for(int i=0;i<n;i++){
            for(int j=0;j<graph[i].size();j++){
                adj[graph[i][j]].push_back(i);
            }
        }

        unordered_map<int,bool>unsafe;
       
        while(!q.empty()){
            int node=q.front();
            q.pop();
            // cout<<node<<endl;
            for(auto i:adj[node]){
                 outdegree[i]--;
                // cout<<i<<" "<<outdegree[i]<<endl;
               
                if(outdegree[i]==0){
                    q.push(i);
                    ans.insert(i);
                }
            }
            // cout<<endl;
        }
        vector<int>result;
        for(auto i:ans){
            result.push_back(i);
        }
        return result;


    }
};