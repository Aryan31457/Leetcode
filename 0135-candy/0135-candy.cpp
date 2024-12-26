class Solution {
public:
    int candy(vector<int>& ratings) {
        int i=1;
        int n=ratings.size();
        int ans=n;
        while(i<n){
            int cnt=0;

            while(i<n && ratings[i-1]==ratings[i]){
                i++;
            }

            while(i<n && ratings[i-1]<ratings[i]){
                cnt++;
                ans+=cnt;
                i++;
            }
            int cnt1=0;
            while(i<n && ratings[i-1]>ratings[i]){
                cnt1++;
                ans+=cnt1;
                i++;
            }


            //    /
            //   / 
            //  /  \
            // /    \
            //ek point pr overlap hoga isliye uska mini minus krn padega
            ans-=min(cnt,cnt1);
        }
        return ans;
    }
};