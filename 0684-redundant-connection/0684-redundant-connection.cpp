class Solution {
public:
    vector<int> mappi;

  
    int find(int x) {
        if (mappi[x] == -1) return x;
        return mappi[x] = find(mappi[x]); 
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        mappi.resize(n + 1, -1);

        int ans = -1;

        for (int i = 0; i < n; i++) {
            int a = edges[i][0];
            int b = edges[i][1];

            int g1 = find(a);
            int g2 = find(b);

            if (g1 == g2) {
                ans = i;
            } else {
                mappi[g1] = g2; 
            }
        }

        if (ans != -1) {
            return {edges[ans][0], edges[ans][1]};
        }
        return {};
    }
};
