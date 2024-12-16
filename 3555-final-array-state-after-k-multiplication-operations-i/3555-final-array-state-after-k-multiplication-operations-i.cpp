class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int n=nums.size();
        vector<int>ans(n,0);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(int i=0;i<n;i++){
            pq.push({nums[i],i});
        }
        for(int i=0;i<k;i++){
            auto x=pq.top();
            pq.pop();
            pq.push({x.first*multiplier,x.second});
        }
        while(!pq.empty()){
            auto x=pq.top();
            ans[x.second]=x.first;
            pq.pop();
        }
        return ans;
    }
};