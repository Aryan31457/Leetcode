class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int n=nums.size();
         for(int i=0;i<n;i++){
            
            int prev=-1;
            int next=-1;
            int curr=nums[i];
            if(i-1>=0){
                prev=nums[i-1];
            }
            if(i+1<n){
                next=nums[i+1];
            }
            if(prev!=-1 && prev%2==curr%2){
              return false;
            }
        }
        return true;
    }
};