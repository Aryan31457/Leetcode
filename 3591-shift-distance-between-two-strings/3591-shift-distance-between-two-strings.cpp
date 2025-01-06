class Solution {
public:
    long long shiftDistance(string s, string t, vector<int>& nextCost, vector<int>& previousCost) {
        vector<long long> next(26, 0), prev(26, 0); 
        long long prevsum = 0, nextsum = 0;

        for (int i = 0; i < 26; i++) {
            nextsum += nextCost[i];
            next[i] = nextsum;
        }

        for (int i = 0; i <26; i++) {
            prevsum += previousCost[i];
            prev[i] = prevsum;
        }

        long long ans = 0;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            // cout<<i<<endl;
            int diff = t[i] - s[i]; 
            // cout<<diff<<endl;
            if (diff > 0) {
                long long nextcost = next[t[i] - 'a'] - next[s[i] - 'a'] +nextCost[s[i] - 'a']-nextCost[t[i] - 'a'];
                long long prevcost = prevsum - (abs(prev[t[i] - 'a'] - prev[s[i] - 'a'])) ;
            // cout<<prevcost<<" "<<nextcost<<endl;

                ans += min(nextcost, prevcost);
            }
             else if (diff <0) {
                long long nextcost = nextsum - (next[s[i] - 'a'] -next[t[i] - 'a'] )+nextCost[s[i]-'a']-nextCost[t[i] - 'a'];
                long long prevcost = prev[s[i] - 'a'] - prev[t[i] - 'a'] ;
            // cout<<prevcost<<" "<<nextcost<<endl;

                ans += min(nextcost, prevcost);
            }
        }

        return ans;
    }
};
