class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>ans;
       
        int start=newInterval[0];
        int last=newInterval[1];
        int n=intervals.size();
        bool flag=false;
        for(int i=0;i<n;i++){
            if(intervals[i][1]<start || flag){
                ans.push_back({intervals[i][0],intervals[i][1]});
              
            }
            else{
                int shuru=min(start,intervals[i][0]);
                int khtm=last;
                while(i<n && intervals[i][0]<=last){
                khtm=max(khtm,intervals[i][1]);
                i++;
                } 
                ans.push_back({shuru,khtm});
                flag=true;
                i--;
            }
        }
        if(!flag)
        {
        ans.push_back({newInterval[0],newInterval[1]});
        }
        return ans;
    }
};