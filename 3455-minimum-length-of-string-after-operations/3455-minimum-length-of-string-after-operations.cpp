class Solution {
public:
    int minimumLength(string s) {
        int n=s.size();
        unordered_map<int, int> mappi1;
        for (auto i : s)
            mappi1[i - 'a']++;

        int cnt = 0;

        unordered_map<int, int> mappi2;

        for (auto i : s) {
            mappi1[i-'a']--;
            if (mappi1[i - 'a'] > 0 && mappi2[i - 'a'] > 0){
                mappi1[i-'a']--;
                mappi2[i-'a']--;
                cnt+=2;
            }
            mappi2[i-'a']++;
        }
        return n-cnt;
    }
};