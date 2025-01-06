class Solution {
public:
    vector<int> minOperations(string boxes) {
       vector<int>fill;
       int n=boxes.size();
       for(int i=0;i<n;i++)
       {
        if(boxes[i]=='1')fill.push_back(i);
       } 
       int x=fill.size();
       vector<int>result;
       for(int i=0;i<n;i++){
        int ans=0;
        for(int j=0;j<x;j++){
            ans+=abs(i-fill[j]);
        }
        result.push_back(ans);
       }
       return result;
    }
};