// #define mod 1000000007
class Solution {
public:
     long long sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> leftsmall(n, -1), rightsmall(n, n);
        stack<int> s;

        for (int i = 0; i < n; i++) {
            while (!s.empty() && arr[s.top()] >= arr[i]) {
                s.pop();
            }
            if (!s.empty()) {
                leftsmall[i] = s.top();
            }
            s.push(i);
        }

        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            if (!st.empty()) {
                rightsmall[i] = st.top();
            }
            st.push(i);
        }

        long long int ans = 0;
        for (int i = 0; i < n; i++) {
            long long int contribution = ((long long)(i - leftsmall[i]) * (rightsmall[i] - i)) ;
            ans = (ans + (contribution * arr[i]) ) ;
        }

        return ans;
    }
     long long  sumSubarrayMaxs(vector<int>& arr) {
        //for maxi
        int n = arr.size();
        vector<int> leftsmall(n, -1), rightsmall(n, n);
        stack<int> s;

        for (int i = 0; i < n; i++) {
            while (!s.empty() && arr[s.top()] <= arr[i]) {
                s.pop();
            }
            if (!s.empty()) {
                leftsmall[i] = s.top();
            }
            s.push(i);
        }

        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] < arr[i]) {
                st.pop();
            }
            if (!st.empty()) {
                rightsmall[i] = st.top();
            }
            st.push(i);
        }

        long long int ans = 0;
        for (int i = 0; i < n; i++) {
            long long int contribution = ((long long)(i - leftsmall[i]) * (rightsmall[i] - i)) ;
            ans = (ans + (contribution * arr[i]) ) ;
        }

        return ans;
    }
    long long subArrayRanges(vector<int>& nums) {
        return  sumSubarrayMaxs(nums) - sumSubarrayMins(nums);
        
    }
};