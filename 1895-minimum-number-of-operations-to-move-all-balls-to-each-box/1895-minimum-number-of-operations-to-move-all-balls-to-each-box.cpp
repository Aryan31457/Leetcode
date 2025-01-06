class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n=boxes.size();
        vector<pair<int,int>>pre(n,{0,0}),suf(n,{0,0});
        int cnt1=0,cnt2=0;
        int n1=0,n2=0;
        for(int i=0;i<n;i++){
          

            pre[i].first=cnt1;
            pre[i].second=n1;

            suf[n-i-1].first=cnt2;
            suf[n-i-1].second=n2;
            if(boxes[i]=='1')
            {cnt1+=i;
            n1++;}
            if(boxes[n-i-1]=='1')
            {cnt2+=n-i-1;
            n2++;}
        }
        vector<int>result(n,0);
        for(int i=0;i<n;i++){
            int n1=pre[i].second,n2=suf[i].second;
            // cout<<(i*n1)-pre[i].first<<" "<<suf[i].first-(i*n2)<<endl;
            result[i]=(i*n1)-pre[i].first+suf[i].first-(i*n2);
        }
        return result;
    }
};