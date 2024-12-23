class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& arr) {
        vector<int>ans;
        int n=arr.size();
        for(int i=0;i<n;i++){
            arr[abs(arr[i])-1]=-abs( arr[abs(arr[i])-1]);
        }
        for(int i=0;i<n;i++){
            if(arr[i]>0){
                ans.push_back(i+1);
            }
        }
        return ans;
    }
};