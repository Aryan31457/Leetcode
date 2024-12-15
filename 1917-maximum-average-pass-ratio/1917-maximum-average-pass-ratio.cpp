class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<double,pair<int,int>>>pq;
        int n=classes.size();
        for(int i=0;i<n;i++){
            double ratio=(double)(classes[i][0]+1)/((double)classes[i][1]+1 ) -(double)classes[i][0]/(double)classes[i][1];
            pq.push({ratio,{classes[i][0],classes[i][1]}});
        }
        int m=extraStudents;
        for(int i=0;i<m;i++){
            auto temp=pq.top();
            pq.pop();
            double pass= temp.second.first+1;
            double total= temp.second.second+1;
            double ratio=(double)(pass+1)/(double)(total+1) - (double)pass/(double)total;
            pq.push({ratio,{pass,total}});
        }
        double ans=0;
        while(!pq.empty()){
            auto temp=pq.top();
            double pass= temp.second.first;
            double total= temp.second.second;
            double ratio=(double) pass/(double) total;
            ans+=ratio;
            pq.pop();
        }
        return ans/n;
    }
};