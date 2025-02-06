class Solution {
public:
    int tupleSameProduct(vector<int>& arr) {
        unordered_map<int,int>mappi;
        int n=arr.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int pro=arr[i]*arr[j];
                mappi[pro]++;
            }
        }
        int ans=0;
        for(auto i:mappi){
            if(i.second>1){
                ans+=((i.second)*(i.second-1)/2)*8;
            }
        }
        return ans;
    }
};