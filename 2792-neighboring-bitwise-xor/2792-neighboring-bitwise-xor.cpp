class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int xori=0;
        for(auto i:derived)xori^=i;
        if(xori==0)return true;
        return false;
    }
};