class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_map<int,int>mappi;
        for(int i=0;i<banned.size();i++){
            mappi[banned[i]]++;
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            if(mappi[i]==0){
            if(maxSum - i>=0 ){
                ans++;
                maxSum-=i;
            }
            else{
                break;
            }
            }
        }
        return ans;
    }
};