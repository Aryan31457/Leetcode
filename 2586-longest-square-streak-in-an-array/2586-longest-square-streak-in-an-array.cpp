class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        set<int>mappi;
        for(auto i:nums)mappi.insert(i);

        int ans=0;
        int n=nums.size();
        for(int i=0;i<n;i++){

            int cnt=0;
            long long temp=(long)nums[i];
            while(cnt<=5){
                if(mappi.find(temp)==mappi.end())break;
                cnt++;
                if(temp*temp>INT_MAX){break;}
                temp*=temp;
            }
            ans=max(cnt,ans);
        }
        if(ans<2)return -1;
        return ans;
    }
};