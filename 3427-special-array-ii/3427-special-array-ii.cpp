class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& query) {
        int n=nums.size();
        vector<int>chk(n);
        int cnt=1;
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
                cnt++;
            }
            
            // else if(curr!=-1 && curr%2==next%2){
            //     cnt++;
            // }
            chk[i]=cnt;
        }
        vector<bool>ans;
        for(int i=0;i<query.size();i++){
            if(chk[query[i][0]]!=chk[query[i][1]]){
                ans.push_back(false);
            }
            else{
                ans.push_back(true);
            }
        }
        return ans;

    }
};