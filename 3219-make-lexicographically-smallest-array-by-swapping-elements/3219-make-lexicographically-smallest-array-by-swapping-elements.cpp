class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n=nums.size();
        vector<int>temp=nums;
        sort(temp.begin(),temp.end());

        unordered_map<int,int>mappi;
        unordered_map<int,multiset<int>>group;

        int cnt=0;
        mappi[temp[0]]=0;
        group[cnt].insert(temp[0]);
        for(int i=1;i<n;i++){
            if(temp[i]-temp[i-1]>limit)cnt++;

            mappi[temp[i]]=cnt;
            group[cnt].insert(temp[i]);
        }

       for (int i = 0; i < n; i++) {
        auto it = group[mappi[nums[i]]].begin(); 
        nums[i] = *it;                         
        group[mappi[nums[i]]].erase(it);      
        }   
        return nums;



    }
};