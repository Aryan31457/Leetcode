class Solution {
public:
    void dfs(int i,vector<vector<int>>& adj,vector<int>&visited){
        visited[i]=1;
        int n=adj.size();
        for(int x=0;x<n;x++){
            if(adj[i][x]==1){
            if(visited[x]==-1){
                dfs(x,adj,visited);
            }
            }
        }
        return;
    }
    int findCircleNum(vector<vector<int>>&adj) {
        int n=adj.size();
        vector<int>visited(n,-1);
        int ans=0;
        for(int i=0;i<n;i++){
            if(visited[i]==-1){
                dfs(i,adj,visited);
                ans++;
            }
        }
        return ans;
    }
};