class Solution {
public:
    int atMostKDistinct(vector<int>& nums, int k) {
        int i = 0, j = 0, n = nums.size();
        unordered_map<int, int> mappi;
        int count = 0;

        while (i < n) {
            mappi[nums[i]]++;
            if (mappi[nums[i]] == 1) { // New distinct number
                k--;
            }
            
            while (k < 0) { // Shrink window if too many distinct integers
                mappi[nums[j]]--;
                if (mappi[nums[j]] == 0) {
                    k++;
                }
                j++;
            }

            count += (i - j + 1); // Count subarrays ending at `i`
            i++;
        }

        return count;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMostKDistinct(nums, k) - atMostKDistinct(nums, k - 1);
    }
};
