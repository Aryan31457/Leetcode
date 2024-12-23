class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        multiset<int> window;
        long long ans = 0;
        int n = nums.size();
        int i = 0, j = 0;

        while (i < n) {
            window.insert(nums[i]);

            while (*window.rbegin() - *window.begin() > 2) {
                window.erase(window.find(nums[j]));
                j++;
            }

            ans += (i - j + 1);
            i++;
        }

        return ans;
    }
};
