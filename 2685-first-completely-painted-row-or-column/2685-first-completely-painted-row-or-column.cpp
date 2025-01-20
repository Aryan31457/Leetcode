class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int row=mat.size(),col=mat[0].size();
        unordered_map<int,int>mappirow,mappicol;

        // for(int i=0;i<row;i++){
        //     for(int j=0;j<col;j++){
        //         mappirow[i][mat[i][j]]++;
        //         mappicol[j][mat[i][j]]++;
        //     }
        // }   

        unordered_map<int,pair<int,int>>mappi;

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                mappi[mat[i][j]]={i,j};
            }
        } 
        
        int n=arr.size();


        for(int i=0;i<n;i++){
            int num=arr[i];
            auto x=mappi[arr[i]];
            mappirow[x.first]++;
            mappicol[x.second]++;
            if( mappirow[x.first]==col|| mappicol[x.second]==row){
                return i;
            }
        }

    return n-1;
    }
};