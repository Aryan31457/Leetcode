class Solution {
public:
    int minMoves2(vector<int>& nums) {
        // average fails
        // int n=nums.size();
        // long long sum=0;
        // for(int i=0;i<n;i++){
        //     sum+=nums[i];
        // }
        // sum=sum/2;
        // int ans=0;
        //  for(int i=0;i<n;i++){
        //     ans+=abs(sum-nums[i]);
        // }
        // return ans;

        //median
        int n=nums.size();

        if(n==1){return 0;}
        sort(nums.begin(),nums.end());
        int mid1=n/2,mid2=n/2-1;
        int sum1=0,sum2=0;
        for(int i=0;i<n;i++){
             sum1+=abs(nums[mid1]-nums[i]);
             if(mid2>=0){
             sum2+=abs(nums[mid2]-nums[i]);
             }
         }
         if(mid2<0){
            mid2=INT_MAX;
         }
         return min(sum1,sum2);

    }
};