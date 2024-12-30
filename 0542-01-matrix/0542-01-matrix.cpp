class Solution {
public:
  void bfs( queue<pair<int,int>>&q,vector<vector<int>>& adj,vector<vector<int>>&visited){
        int m = adj.size(), n = adj[0].size();
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int cnt=1;
        while(!q.empty()){
            int x=q.size();
            for(int i=0;i<x;i++){
                auto [row, col] = q.front();
                q.pop();
                for (auto [dx, dy] : directions) {
                    int newRow = row + dx;
                    int newCol = col + dy;

if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && visited[newRow][newCol]==0 ) {
                        adj[newRow][newCol] = cnt;
                        visited[newRow][newCol]=1;
                        q.push({newRow, newCol});
                    }
                }
            }
           cnt++;
        }
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& adj) {
          int m = adj.size(), n = adj[0].size();
        vector<vector<int>>result(m,vector<int>(n,0));
         queue<pair<int,int>>q;
        vector<vector<int>>visited(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                result[i][j]=adj[i][j];
                if(adj[i][j]==0){
                  visited[i][j] = 1;
                  result[i][j]=0;
                  q.push({i,j});
                }
            }
        }
        bfs(q,result,visited);
        return result;
    }
};