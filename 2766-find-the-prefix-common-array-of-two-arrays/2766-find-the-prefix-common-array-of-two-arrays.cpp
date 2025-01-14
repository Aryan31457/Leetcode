class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_map<int,int>mappi1,mappi2;
        int cnt=0;
        int n=A.size();
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(mappi1[A[i]]!=0  && mappi1[A[i]]==mappi2[A[i]]){
                cnt--;
            }
            if(A[i]!=B[i] && mappi1[B[i]]!=0 && mappi1[B[i]]==mappi2[B[i]]){
                cnt--;
            }
            mappi1[A[i]]++;
            mappi2[B[i]]++;
            if(mappi1[A[i]]==mappi2[A[i]]){
                cnt++;
            }
            if(A[i]!=B[i] && mappi1[B[i]]==mappi2[B[i]]){
                cnt++;
            }
            ans.push_back(cnt);

        }

        return ans;
    }
};