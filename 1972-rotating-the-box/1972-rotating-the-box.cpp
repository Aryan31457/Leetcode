class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int n=box.size(),m=box[0].size();
       vector<vector<char>>ans(m,vector<char>(n,'.'));

       for(int i=0;i<n;i++){
             for(int j=0;j<m;j++){
            int temp=j;
            if(box[i][j]=='#'){
                while(j<m && box[i][j]!='.'&& box[i][j]!='*'){
                    j++;
                }
                if(j<m && box[i][j]=='.'){
                    swap(box[i][j],box[i][temp]);
                    j=temp;
                }
                else{
                    continue;
                }
            }
        }

       } 
       
       for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            ans[j][i]=box[n-i-1][j];
        }
       }
       return ans;
    }
};