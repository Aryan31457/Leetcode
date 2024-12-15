class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start=0;
        int curr=0;
        int tgas=0,tcost=0;
        int n=gas.size();
        for(int i=0;i<n;i++){
            tgas+=gas[i];
            tcost+=cost[i];

            curr+=gas[i]-cost[i];

            if(curr<0){
                start=i+1;
                curr=0;
            }
        }
        if(tgas>=tcost && start<n)return start;
        return -1;
    }
};