class Solution {
public:
    vector<int> asteroidCollision(vector<int>& as) {
        stack<int> s;
        for (int i = 0; i < as.size(); i++) {
            bool destroyed = false;
            while (!s.empty() && s.top() > 0 && as[i] < 0) {
                if (s.top() < abs(as[i])) {
                    s.pop();
                } else if (s.top() == abs(as[i])) {
                    s.pop();
                    destroyed = true;
                    break;
                } else {
                    destroyed = true;
                    break;
                }
            }
            if (!destroyed) {
                s.push(as[i]);
            }
        }
        vector<int> ans;
        while (!s.empty()) {
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
