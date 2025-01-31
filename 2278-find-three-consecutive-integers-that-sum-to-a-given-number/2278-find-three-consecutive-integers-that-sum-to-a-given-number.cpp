class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        long long rem=num%3;
        vector<long long>ans;
        if(rem==0){
            long long dig=num/3;
            ans.push_back(dig-1);
            ans.push_back(dig);
            ans.push_back(dig+1);
        }
        return ans;
    }
};