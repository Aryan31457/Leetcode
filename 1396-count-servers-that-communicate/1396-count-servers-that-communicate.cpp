class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        unordered_map<int,int>rmappi,cmappi;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]){
                    rmappi[i]++;
                    cmappi[j]++;
                }
            }
        }
        int ans=0;
         for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]){
                   if(rmappi[i]>1 || cmappi[j]>1)ans++;
                }
            }
        }
        return ans;
    }
};