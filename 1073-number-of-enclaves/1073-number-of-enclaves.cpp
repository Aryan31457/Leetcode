class Solution {
public:
    int numEnclaves(vector<vector<int>>& adj) {
         int m=adj.size(),n=adj[0].size();
        vector<vector<int>> visited(m, vector<int>(n, -1));
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        queue<pair<int,int>>q;
        bool flag=false;
        for(int i=0;i<m;i++){
          
            for(int j=0;j<n;j++){
                if(adj[i][j]==1){
                    flag=true;
                    visited[i][j]=1;
                    q.push({i,j});
                    break;
                }
            }
              if(flag)break;
        }
           for(int i=0;i<m;i++){
            if(adj[i][0]==1){
                q.push({i,0});
                visited[i][0]=1;
            }
            if(adj[i][n-1]==1){
                 q.push({i,n-1});
                 visited[i][n-1]=1;
            }
        }
          for(int i=1;i<n-1;i++){
            if(adj[0][i]==1){
                q.push({0,i});
                visited[0][i]=1;
            }
            if(adj[m-1][i]==1){
                 q.push({m-1,i});
                 visited[m-1][i]=1;
            }
        }
         while(!q.empty()){

                pair<int,int>front=q.front();
                int row=front.first,col=front.second;
                visited[row][col] = 1;
                q.pop();
                 for (auto [dx, dy] : directions) {
                    int newRow = row + dx;
                    int newCol = col + dy;

                    if (newRow >= 0 && newRow < m && newCol >= 0 &&
                        newCol < n && adj[newRow][newCol] == 1 &&
                        visited[newRow][newCol] == -1) {
                        visited[newRow][newCol] = 1;
                        q.push({newRow, newCol});
                    }
                }
                
        }
        int ans=0;

         for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(adj[i][j]==1 && visited[i][j]==-1){
                    ans++;
                }
            }
        }
        return ans;


    }
};