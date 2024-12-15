class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        stack<int>s;
        s.push(nums[0]);
        int i=0,n=nums.size();
        if(k%2==1 && n==1){return -1;}
        int maxi=0;
        for(int i=0;i<k-1 && i<n;i++){
        maxi=max(maxi,nums[i]);
        }
        if(k<n && maxi<nums[k]){
            maxi=nums[k];
        }
       return maxi;
    }
};