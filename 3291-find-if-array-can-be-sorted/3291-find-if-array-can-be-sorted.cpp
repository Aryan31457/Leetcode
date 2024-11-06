class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int n=nums.size();
        int mini=nums[0],maxi=nums[0];
        int prev_max=maxi,prev_min=mini;
        int cnt=__builtin_popcount(nums[0]);
       for(int i=0;i<n;i++){

        int temp=__builtin_popcount(nums[i]);
        if(temp==cnt){
            maxi=max(maxi,nums[i]);
            mini=min(mini,nums[i]);
        }
        else{
            prev_max=maxi;
            prev_min=mini;
            cnt=temp;
            maxi=0,mini=INT_MAX;
            while(i<n){
            int tempo=__builtin_popcount(nums[i]);
            if(tempo==cnt){
            maxi=max(maxi,nums[i]);
            mini=min(mini,nums[i]);
            }
            else{
                cnt=temp;
                i--;
                break;
            }
            i++;
            }
            if(prev_max>mini){return false;}
        }
       } 
       return true;
    }
};