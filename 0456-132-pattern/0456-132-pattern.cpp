class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n=nums.size();
        stack<int>s;
        int smax=INT_MIN;
        for(int i=n-1;i>=0;i--){
            if(nums[i]<smax){
                return true;
            }
            else {
                while(!s.empty() && s.top()<nums[i]){
                    smax=s.top();
                    s.pop();
                }
            } 
            s.push(nums[i]);
        }
        return false;
    }
};