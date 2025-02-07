class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int,int>mappi;
        unordered_map<int,int>mapping;
        int cnt=0;
        vector<int>ans;
        int n=queries.size();
        for(int i=0;i<n;i++){
            int ball=queries[i][0];
            int color=queries[i][1];

            if(mapping[ball]==0){
                mapping[ball]=color;
                mappi[color]++;
                if(mappi[color]==1){
                    cnt++;
                }
            }
            else{
                mappi[mapping[ball]]--;
                if(mappi[mapping[ball]]==0){
                    cnt--;
                }
                mapping[ball]=color;
                mappi[color]++;
                if(mappi[color]==1){
                    cnt++;
                }

            }

            ans.push_back(cnt);

        }
        return ans;

    }
};