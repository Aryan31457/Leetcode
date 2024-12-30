class Solution {
public:
    void bfs(int i,vector<vector<int>>& adj,vector<int>&visited){
          int n=adj.size();
            queue<int>q;
            q.push(i);
            visited[i]=1;
            while(!q.empty()){
                int fronti=q.front();
                q.pop();
                for(int x=0;x<n;x++){
                    if(adj[fronti][x]==1 && visited[x]==-1){
                        q.push(x);
                        visited[x]=1;
                    }
                }
            }
            return ;
    }
    int findCircleNum(vector<vector<int>>&adj) {
        int n=adj.size();
        int ans=0;
          vector<int>visited(n,-1);
          for(int i=0;i<n;i++){
            if(visited[i]==-1){
            ans++;
            bfs(i,adj,visited);
            }
          }
          return ans;
    }
};