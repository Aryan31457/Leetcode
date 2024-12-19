class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n=arr.size();
        int s=0,e=n-1;
        while(s<=e)
        {
            int mid=(s+e)/2;
            int diff=(arr[mid]-mid-1);
            if(diff>=k){
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return k+s;
    }
};