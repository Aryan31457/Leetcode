class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        int cnt=0;
        long long ans=0;
        int mini=INT_MAX;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                 if(matrix[i][j]<0)cnt++;
                 matrix[i][j]=abs(matrix[i][j]);
                mini=min(mini,matrix[i][j]);
                ans+=matrix[i][j];
            }
        }
        if(cnt%2!=0)ans-=2*mini;
        return ans;
    }
};