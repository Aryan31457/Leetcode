class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& start, vector<int>& end) {
       int ans=0;
       int n=start.size();
       vector<int>gap(n+1);
       gap[0]=start[0];
       gap[n]=eventTime-end[n-1];


       for(int i=1;i<n;i++){
        gap[i]=start[i]-end[i-1];
        }
        int g=n+1;
        int i=0,j=0;
        int window=0;
        while(i<g){
          
            if(i-j>k){
                window-=gap[j];
                j++;
            }
            window+=gap[i];
            i++;

            ans=max(ans,window);
        }
        return ans;

    }
};