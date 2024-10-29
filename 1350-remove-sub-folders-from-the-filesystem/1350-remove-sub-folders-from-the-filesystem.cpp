class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(),folder.end());
        vector<string>ans;
        int n=folder.size();
        ans.push_back(folder[0]);
        for(int i=1;i<n;i++){
            string last=ans[ans.size()-1];

            last+='/';

            if (folder[i].substr(0, last.size()) != last) {
            ans.push_back(folder[i]);
            }
        }
        return ans;
    }
};