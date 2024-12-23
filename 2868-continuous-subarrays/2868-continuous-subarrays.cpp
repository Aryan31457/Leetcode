class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        unordered_map<int, int> mappi;
        long long ans = 0;
        int n = nums.size();
        int i = 0, j = 0;
        int maxi = 0, mini = INT_MAX;

        while (i < n) {
            mappi[nums[i]]++;
            maxi = max(maxi, nums[i]); 
            mini = min(mini, nums[i]); 

            while (maxi - mini > 2) {
                mappi[nums[j]]--; 
                if (mappi[nums[j]] == 0) {
                    mappi.erase(nums[j]);
                }

                if (nums[j] == maxi || nums[j] == mini) {
                    maxi = INT_MIN;
                    mini = INT_MAX;

                    for (auto entry : mappi) {
                        maxi = max(maxi, entry.first);
                        mini = min(mini, entry.first);
                    }
                }

                j++;  
            }

            ans += (i - j + 1);
            i++;
        }

        return ans;
    }
};
