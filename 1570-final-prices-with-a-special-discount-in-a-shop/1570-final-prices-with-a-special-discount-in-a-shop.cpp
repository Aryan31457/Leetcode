class Solution {
public:
    void next_smaller(vector<int>&prices,vector<int>&small){
        stack<int>st;
        int n=prices.size();
        for(int i=0;i<n;i++){
            while(!st.empty() && prices[st.top()]>=prices[i]){
                small[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }
    }
    vector<int> finalPrices(vector<int>& prices) {
        int n=prices.size();
        vector<int>small(n,-1);
        next_smaller(prices,small);
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            ans[i]=prices[i];
            if(small[i]!=-1){
                ans[i]-=prices[small[i]];
            }
        }
        return ans;

    }
};