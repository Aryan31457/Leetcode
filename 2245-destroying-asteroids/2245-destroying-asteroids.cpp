class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& as) {
        sort(as.begin(),as.end());
        long long temp=mass;
        int n=as.size();
        for(int i=0;i<n;i++){
            if(temp<as[i]){return false;}
            temp+=as[i];
        }
        return true;
    }
};