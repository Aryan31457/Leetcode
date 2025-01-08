class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int ans=0;
        int n=words.size();
        for(int i=0;i<n;i++){
            string temp=words[i];
            string tempo=temp;
            reverse(tempo.begin(),tempo.end());
            // cout<<i<<" "<<temp<<" "<<tempo<<endl;

            int x=temp.size();
            for(int j=i;j<n;j++){
                int y=words[j].size();
                string z=words[j];
                if(i!=j && x<=y){
                    string pre=z.substr(0,x);
                    string suf=z.substr(y-x,x);
                    reverse(suf.begin(),suf.end());
                    // cout<<pre<<" "<<suf<<endl;
                    
                    if(temp==pre && tempo==suf){
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};