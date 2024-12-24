class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        vector<int>ans;
        int n=mat.size(),m=mat[0].size();
        int maxi=-1,max_idx=-1;
        for(int i=0;i<n;i++){
            int temp=0;
            for(int j=0;j<m;j++){
                temp+=mat[i][j];
            }
            if(temp>maxi){
                maxi=temp;
                max_idx=i;
            }
        }
        ans.push_back(max_idx);
        ans.push_back(maxi);
        return ans;

    }
};