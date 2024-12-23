class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int>pq;
        for(int i=0;i<gifts.size();i++){
            pq.push(gifts[i]);
        }
        while(k-- && pq.top()!=1){
            int topi=pq.top();
            pq.pop();
            topi=sqrt(topi);
            pq.push(topi);
        }
        long long ans=0;
        while(!pq.empty()){
            cout<<pq.top()<<" ";
            ans+=pq.top();
            pq.pop();
        }
        return ans;

    }
};