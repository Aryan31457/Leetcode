class Solution {
public:
    bool isValid(int i,int j, int row,int col){
        if(row>=i || col>=j ||row<0 || col<0)return false;
        return true;
    }
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n=isWater.size(),m=isWater[0].size();
        vector<vector<int>>dirs={{-1,0},{0,-1},{1,0},{0,1}};
        vector<vector<int>>ans(n,vector<int>(m,0));
        vector<vector<int>>visited(n,vector<int>(m,-1));
        
        queue<pair<int,int>>q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(isWater[i][j]){
                    q.push({i,j});
                    visited[i][j]=1;
                    }
            }
        }
        int cnt=1;
        while(!q.empty()){
            int x=q.size();
            for(int i=0;i<x;i++){
                auto [row,col]=q.front();
                q.pop();
                for(int i=0;i<4;i++){
                    int nrow=row+dirs[i][0];
                    int ncol=col+dirs[i][1];
                    if(isValid(n,m,nrow,ncol) && visited[nrow][ncol]==-1){
                        q.push({nrow,ncol});
                         visited[nrow][ncol]=1;
                         ans[nrow][ncol]=cnt;
                    }
                }
            }
            cnt++;
        }
    return ans;
    }
};