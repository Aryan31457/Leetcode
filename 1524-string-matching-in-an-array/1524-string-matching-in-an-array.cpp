class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {

        vector<string>ans;
        int n=words.size();
         for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j < words.size(); j++) {
               if (i != j) {
                   auto found = words[j].find(words[i]);
                   //npos -> not found at any position returns -1
                   if (found != string::npos) {
                       ans.push_back(words[i]);
                       break;
                   }
               }
            }
        }
        return ans;

    }
};