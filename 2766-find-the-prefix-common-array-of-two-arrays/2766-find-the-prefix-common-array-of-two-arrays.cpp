class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_map<int,int>mappi1;
        int cnt=0;
        int n=A.size();
        vector<int>ans;
        for(int i=0;i<n;i++){

            mappi1[A[i]]++;
            
            if(mappi1[A[i]]==2){
                cnt++;
            }
            mappi1[B[i]]++;
            
            if(mappi1[B[i]]==2){
                cnt++;
            }
            ans.push_back(cnt);

        }

        return ans;
    }
};