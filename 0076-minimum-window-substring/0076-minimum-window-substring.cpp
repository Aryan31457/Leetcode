class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> mappi(128, 0);
        for (char i : t) {
            mappi[i]++;
        }

        int remain = t.size();
        int left = 0, right = 0;
        int mini = INT_MAX;
        int start = 0;

        while (right < s.size()) {
            if (mappi[s[right]] > 0) {
                remain--;
            }
            mappi[s[right]]--;
            right++;

            while (remain == 0) {
                if (right - left < mini) {
                    mini = right - left;
                    start = left;
                }

                mappi[s[left]]++;
                if (mappi[s[left]] > 0) {
                    remain++;
                }
                left++;
            }
        }

        return mini == INT_MAX ? "" : s.substr(start, mini);
    }
};
