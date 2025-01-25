class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {

        vector<int>outdegree(n);
        queue<int>q;
        unordered_map<int,vector<int>>adj;
        int c=0;
        for(int i=0;i<pre.size();i++){  
            adj[pre[i][1]].push_back(pre[i][0]);
            outdegree[pre[i][0]]++;
        } 

        for(int i=0;i<n;i++){
            if(outdegree[i]==0){
                q.push(i);
            }
        }
        vector<int>ans;
        while(!q.empty()){

            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto i:adj[node]){
                outdegree[i]--;
                if(outdegree[i]==0){
                    q.push(i);
                }
            }
        }     

        return ans.size() == n ? ans : vector<int>{};
    }
};