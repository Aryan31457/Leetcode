class Solution {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
        long long maxi=0;
        long long int n=segments.size();
        for(int i=0;i<n;i++){
            maxi=max(maxi,(long long)segments[i][1]);
        }
        vector<long long int>count(maxi+1,0);
        vector<long long int>khtm(maxi+1,0);

       
        for(int i=0;i<n;i++){
            long long int st=segments[i][0];
            long long int e=segments[i][1];
            long long int p=segments[i][2];
         
            count[st]+=p;
            
            count[e]-=p;
            khtm[e]=-1;
            
          
        }
        long long int cnt=0;
        
        for(int i=1;i<maxi+1;i++){
            
            cnt+=count[i];
            count[i]=cnt;
           
        }
        vector<vector<long long>>ans;
        long long s=1,c=-1,e=-1;
        
        for(int i=1;i<maxi;i++){
           
            if( (c>-1 && count[i]!=c )||khtm[i]==-1){
                if(c!=0){
                ans.push_back({s,i,c});
                c=count[i];
                s=i;
                }
                else{
                    c=count[i];
                    s=i;
                }
            }
            if(c==-1 && count[i]>0){
                s=i;
                c=count[i];}
            if(count[i]>0){
               e=i;}
        }
         ans.push_back({s,e+1,c});
              
        return ans;

    }
};