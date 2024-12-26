class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
    if (a[1] == b[1]) {
        return a[0] < b[0];
    }
    return a[1] < b[1];
    });
        int ans=0;
        int end=INT_MIN;
        int n=intervals.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            if(intervals[i][0]>=end){
                cnt++;
                end=intervals[i][1];
            }
            else{
                continue;
            }
        }
        // cnt se maximum number of non overlapping intevals nikal liye , remainning agaye need to be removed wle
        return n-cnt;
      
    }
};