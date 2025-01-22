class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
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
        vector<vector<int>>ans(n,vector<int>(m,0));
         for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
               int rone=rmappi[i];
               int cone=cmappi[j];
            //    cout<<rone<<" "<<cone<<endl;
               int rzero=n-rone;
               int czero=m-cone;
                // cout<<rzero<<" "<<czero<<endl;
               ans[i][j]=rone+cone-rzero-czero;
            }
        }
        return ans;

    }
};