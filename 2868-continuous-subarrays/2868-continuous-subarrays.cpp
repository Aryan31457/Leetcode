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
                if (nums[j] == maxi) {
                    int temp = INT_MIN;
                    mappi[nums[j]]--;
                    if (mappi[nums[j]] == 0)
                        mappi.erase(nums[j]);

                    for (const auto& [key, count] : mappi) {
                        if (count > 0)
                            temp = max(temp, key);
                    }
                    maxi = temp;
                } else if (nums[j] == mini) {
                    int temp = INT_MAX;
                    mappi[nums[j]]--;
                    if (mappi[nums[j]] == 0)
                        mappi.erase(nums[j]);

                    for (const auto& [key, count] : mappi) {
                        if (count > 0)
                            temp = min(temp, key);
                    }
                    mini = temp;
                } else {
                    mappi[nums[j]]--;
                    if (mappi[nums[j]] == 0)
                        mappi.erase(nums[j]);
                }
                j++;
            }

            ans += (i - j + 1);
            i++;
        }

        return ans;
    }
};
