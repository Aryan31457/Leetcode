class Solution {
public:
    int numSpecial(vector<vector<int>>& grid) {
        unordered_map<int,int>rmappi,cmappi;
        int n=grid.size(),m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]){
                rmappi[i]++;
                cmappi[j]++;
                }
            }
        }

        int ans=0;
         for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] && rmappi[i]==1 && cmappi[j]==1){
                    ans++;
                }
            }
        }
        return ans;
    }
};