class Solution {
public:
 int largestRectangleArea(vector<int>& arr) {
        int n=arr.size();
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

        int area=0;
        for(int i=0;i<n;i++){
            int temp=arr[i]*(rightsmall[i]-leftsmall[i]-1);
            area=max(temp,area);
        }
        return area;

    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int result=0;
        int n=matrix[0].size(),m=matrix.size();
        vector<int>heights(n,0);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]=='0'){heights[j]=0;}
                else{
                heights[j]+=(matrix[i][j]-'0');
                }
            }
            int temp=largestRectangleArea(heights);
            result=max(result,temp);
        }
        return result;
    }
};