class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int>mappi(n,0);
        for(auto i:edges){
            mappi[i[1]]++;
        }
        int winner=-1,cnt=0;
       for(int i=0;i<n;i++){
        if(mappi[i]==0){
            winner=i;
            cnt++;
        }
        if(cnt>1){
            break;
        }
       }
       if(cnt==1){return winner;}
        return -1;

    }
};