class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n=speed.size();
        vector<float>time(target+1);
        for(int i=0;i<n;i++){
            time[position[i]]=(float)(target-position[i])/speed[i];
        }
        int ans=0;
        float maxi=0;
        for(int i=target;i>=0;i--){
            if(time[i]>maxi)ans++;
            maxi=max(time[i],maxi);
        }
        return ans;
    }
};