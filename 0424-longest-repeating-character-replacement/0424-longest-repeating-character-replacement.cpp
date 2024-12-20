class Solution {
public:
    int characterReplacement(string s, int k) {
        int i = 0, j = 0;
        int n = s.size();
        int ans = 0;
        int maxi = 0;
        unordered_map<char, int> mappi;

        while (i < n) {
            mappi[s[i]]++;
            maxi = max(maxi, mappi[s[i]]);
            
            while (i - j + 1 - maxi > k) {
                mappi[s[j]]--;
                j++;
                maxi = 0;
                for (auto it : mappi) {
                    maxi = max(maxi, it.second);
                }
            }

            ans = max(ans, i - j + 1);
            i++;
        }

        return ans;
    }
};
