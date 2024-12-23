class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        vector<pair<int,int>>arr;
        for(int i=0;i<points.size();i++){
            arr.push_back({points[i][0],points[i][1]});
        }
       sort(arr.begin(), arr.end(), []( pair<int, int> &a,  pair<int, int> &b) {
            return a.second < b.second;
        });
        int ans=0;
        long long maxi=LLONG_MIN;
        for(int i=0;i<arr.size();i++){
            if(arr[i].first<=maxi){
                continue;
            }
            else{
                ans++;
                maxi=arr[i].second;
            }
        }
        return ans;
    }
};