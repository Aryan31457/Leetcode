class Solution {
public:
    int max_idx(vector<vector<int>>&mat,int col){
        int m=mat.size();
        int idx=-1;
        int maxi=0;
        for(int i=0;i<m;i++){
            if(mat[i][col]>maxi){
                maxi=mat[i][col];
                idx=i;
            }
        }
        return idx;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        vector<int>ans;
        int m=mat.size(),n=mat[0].size();
        int s=0,e=n;
        while(s<=e){
            int mid=(s+e)/2;
            int x=max_idx(mat,mid);
            int left=-1;
            if(mid-1>=0){left=mat[x][mid-1];}
            int right=-1;
            if(mid+1<n){right=mat[x][mid+1];}
            int val=mat[x][mid];
            if(val>left && val>right){
                ans.push_back(x);
                ans.push_back(mid);
                return ans;
            }
            if(val<left){
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return ans;
    }
};