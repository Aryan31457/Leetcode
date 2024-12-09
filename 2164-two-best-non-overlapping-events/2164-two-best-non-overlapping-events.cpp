class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
    vector<pair<pair<int,int>,int>>temp;

    //temp[i]={{start,end},value}

    int n=events.size();
    for(int i=0;i<n;i++){
        temp.push_back({{events[i][0],events[i][1]},events[i][2]});
    } 
    sort(temp.begin(),temp.end());
    int maxi=0;

    map<int,int>mappi;

    for(int i=n-1;i>=0;i--){
        maxi=max(maxi,temp[i].second);
        mappi[temp[i].first.first]=maxi;
    }
    int ans=0;

    for(int i=0;i<n;i++){

        int curr=temp[i].second;

        auto next=mappi.upper_bound(temp[i].first.second);

        if (next != mappi.end()) {
                curr += next->second;
            }

        ans=max(ans,curr);

    }
    return ans;
    }
};