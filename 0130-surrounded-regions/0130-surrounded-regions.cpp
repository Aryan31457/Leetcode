class Solution {
public:
    void bfs(  queue<pair<int,int>>&q,vector<vector<int>>&visited,vector<vector<char>>& adj){
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int m = adj.size(), n = adj[0].size();

        while (!q.empty()) {
            int size = q.size();
            bool rotted = false;

            for (int k = 0; k < size; k++) {
                auto [row, col] = q.front();
                q.pop();
                visited[row][col]=1;
                for (auto [dx, dy] : directions) {
                    int newRow = row + dx;
                    int newCol = col + dy;
                        if (newRow >= 0 && newRow < m && newCol >= 0 &&
                        newCol < n && adj[newRow][newCol] == 'O' &&
                        visited[newRow][newCol] == -1) {
                        visited[newRow][newCol]=1;
                        q.push({newRow,newCol});
                        }
                }
            }
        }
    }
    void solve(vector<vector<char>>& adj) {
        int m = adj.size(), n = adj[0].size();
        vector<vector<int>> visited(m, vector<int>(n, -1));
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++){
            if(adj[i][0]=='O'){
                q.push({i,0});
                visited[i][0]=1;
            }
            if(adj[i][n-1]=='O'){
                 q.push({i,n-1});
                 visited[i][n-1]=1;
            }
        }
          for(int i=1;i<n-1;i++){
            if(adj[0][i]=='O'){
                q.push({0,i});
                visited[0][i]=1;
            }
            if(adj[m-1][i]=='O'){
                 q.push({m-1,i});
                 visited[m-1][i]=1;
            }
        }
        bfs(q,visited,adj);

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(adj[i][j]=='O' && visited[i][j]==-1){
                    adj[i][j]='X';
                }
            }
        }
    }
};