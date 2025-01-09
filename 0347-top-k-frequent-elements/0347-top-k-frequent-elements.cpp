class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mappi;
        for(auto i:nums){
            mappi[i]++;
        }
        priority_queue<pair<int,int>>pq;
        for(auto i:mappi){
            pq.push({i.second,i.first});
        }
        vector<int>ans;
        for(int i=0;i<k;i++){
            if(!pq.empty()){
                auto x=pq.top();
                pq.pop();

                ans.push_back(x.second);
            }
            else{
                break;
            }
        }
        return ans;
    }
};