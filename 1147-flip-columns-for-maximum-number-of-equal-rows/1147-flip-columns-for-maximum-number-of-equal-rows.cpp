class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        unordered_map<string,int>mappi;
        for(int i=0;i<n;i++){
            int cnt=0;
            string pattern;
            int last=matrix[i][0];
            for(int j=0;j<m;j++){

                if(matrix[i][j]==last){
                    cnt++;
                }
                else{
                    pattern+= to_string(cnt);
                    last=matrix[i][j];
                    cnt=1;
                }

            }
            mappi[pattern]++;
        } 
        int ans=0;
        for(auto i:mappi){
            ans=max(i.second,ans);
        }
        return ans;
    }
};