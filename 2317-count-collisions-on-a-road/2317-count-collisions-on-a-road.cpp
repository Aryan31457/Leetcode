class Solution {
public:
    int countCollisions(string arr) {
        // stack<char>st;
        int n=arr.size();
        int ans=0;
        int right=0;
        char prev=arr[0];
        for(int i=1;i<n;i++){
            if(arr[i]=='L' && prev=='R'){
                ans+=2+right;
                prev='S';
                right=0;
            }
            else if(prev=='R'&& arr[i]=='S'){
                ans+=1+right;
                prev='S';
                right=0;
            }
            else if(prev=='S'&& arr[i]=='L'){
                ans+=1;
                prev='S';
                right=0;
            }
            else{
                if(arr[i]=='R'&&prev=='R'){
                    right++;
                }
                prev=arr[i];
            }
            
        }
        return ans;
    }
};