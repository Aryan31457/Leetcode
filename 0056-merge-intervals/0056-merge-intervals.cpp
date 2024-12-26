class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;
        sort(intervals.begin(),intervals.end());
        int n=intervals.size();
        for(int i=0;i<n;i++)
        {   vector<int>temp;
            if(ans.empty()){
                 ans.push_back(intervals[i]);
            }
            else
            {
                if(ans.back()[1]>=intervals[i][0]){
                ans.back()[1]=max(ans.back()[1],intervals[i][1]);
                }
                else{
                 ans.push_back(intervals[i]);

                }
            }
        }
        return ans;
    }
};