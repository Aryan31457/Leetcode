class Solution {
public:
// bool compare(const pair<int, int>& a, const pair<int, int>& b) {
//     if (a.first == b.first)
//         return a.second < b.second; 
//     return a.first < b.first;    
// }
    long long findScore(vector<int>& nums) {
        int n=nums.size();
        vector<int>marked(n,-1);
        vector<pair<int,int>>arr;
        for(int i=0;i<n;i++){
            arr.push_back({nums[i],i});
        }
        sort(arr.begin(),arr.end(),[] (const pair<int, int>& a, const pair<int, int>& b) {
    if (a.first == b.first)
        return a.second < b.second; 
    return a.first < b.first;    
});
        long long ans=0;
        for(int i=0;i<n;i++){
            int idx=arr[i].second;
            // cout<<idx<<" "<<arr[i].first<<endl;

            if(marked[idx]==-1){
                // cout<<"not visited"<<endl;
                ans+=arr[i].first;
                if(idx-1>=0){
                    marked[idx-1]=0;
                }
                if(idx+1<n){
                    marked[idx+1]=0;
                }
                marked[idx]=0;
            }
            // else{
            //     cout<<"visited"<<endl;

            // }
        }
        return ans;
    }
};