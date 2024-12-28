class Solution {
private:
    int solve(vector<int>& arr, int left, int right, int target) {
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] >= target)
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }

public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();
        int left = 0, right = n - 1;

        while (left + 1 < n && arr[left] <= arr[left + 1]) left++;

        while (right - 1 >= 0 && arr[right] >= arr[right - 1]) right--;

        if (left >= right) return 0;

        int ans = min(n - (left + 1), right);

        for (int i = 0; i <= left; i++) {
            int target = arr[i];
            int j = solve(arr, right, n, target);
            // right wle subaaray ka woh pehla idx jahan se left wla satisfy kr jaaye
            ans = min(ans, j - (i + 1));
        }

        return ans;
    }
};