class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        unordered_map<string ,int>mappi;

        for(auto i:words)mappi[i]++;
        int n=words.size();
        set<string>ans;
        for(int i=0;i<n;i++){
            string x=words[i];
            int m=x.size();
            for(int j=0;j<m;j++){
                string temp;
                for(int k=j;k<m;k++){
                    temp+=x[k];
                    if(mappi[temp]>0 && temp!=x){
                        ans.insert(temp);
                    }
                }
            }
            
        }
        vector<string>result;
        for(auto i:ans){
            result.push_back(i);
        }
        return result;

    }
};