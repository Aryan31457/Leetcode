class Solution {
public:
    int maximumLength(string s) {
        int n=s.size();
        unordered_map<string ,int>mappi;
        for(int i=0;i<n;i++){
            string temp;
            temp+=s[i];
            mappi[temp]++;
            for(int j=i+1;j<n;j++){
                if(s[j]==s[i]){
                    temp+=s[j];
                    mappi[temp]++;
                }
                else{
                    break;
                }  
            }
        }
        int maxi=-1;
        for(auto i:mappi){
            if(i.second>2){
                int t=i.first.size();
                maxi=max(maxi,t);
            }
        }
        return maxi;
    }
};