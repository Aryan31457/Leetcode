class Solution {
public:
    string minWindow(string s1, string s2) {
      if(s2.size()>s1.size())return "";
        unordered_map<char,int>mappi;
        for(auto i:s2)mappi[i]++;
        int mini=INT_MAX;
        string ans="";
        int s=0,e=0;
        int n=s1.size();
        int start=-1;
        int req=mappi.size();
        int cnt=0;
        while(e<n){
            mappi[s1[e]]--;
            
            if(mappi[s1[e]]==0)cnt++;
            
            while(s<=e && cnt==req){
                if(e-s+1<mini){
                    mini=e-s+1;
                    start=s;
                }
                mappi[s1[s]]++;
                if(mappi[s1[s]]>0){
                    cnt--;
                }
                s++;
            }
            e++;
            
        }
        if(start!=-1){
        ans=s1.substr(start,mini);
        }
        return ans;
    }
};
