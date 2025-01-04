class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_map<char,int>mappir,mappil;
        for(auto i:s)mappir[i]++;

        unordered_set<string>set;

        for(auto i:s){
            mappir[i]--;
            vector<bool>chk(26,false);
            for(auto x:mappil){
                if(chk[x.first-'a']==false && mappir[x.first]>0){
                    string temp=string(1, x.first) + i + string(1, x.first);
                    set.insert(temp);
                    chk[x.first-'a']=true;
                }
            }
            mappil[i]++;
        }
        return set.size();

    }
};