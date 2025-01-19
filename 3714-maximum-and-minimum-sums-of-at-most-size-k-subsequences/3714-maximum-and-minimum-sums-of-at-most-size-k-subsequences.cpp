class Solution {
public:
    // long nCr(int n, int r)
    // {
    // if(n<r){return 0;}
    // return fact(n) / (fact(r) * fact(n - r));
    // }
    // long fact(int n)
    // {
    //   if(n==0)
    //   return 1;
    // long res = 1;
    // for (int i = 2; i <= n; i++)
    //     res = res * i;
    // return res;
    // }
    int minMaxSums(vector<int>& nums, int k) {
      sort(nums.begin(),nums.end());
      int mod=1000000007;
        int n=nums.size();

      vector<vector<int>> ncr(n+ 1, vector<int> (k + 1,0));

        ncr[0][0] = 1; 
        for (int i = 1; i <= n; ++i) {
            ncr[i][0] = 1;
            for (int j = 1; j <= k; ++j) {
                 ncr[i][j] = (ncr[i - 1][j] + ncr[i - 1][j - 1]) % mod;
            }
        }

      int ans=0;  
        for(int i=0;i<n;i++){
        for(int x=1;x<=k;x++){
        int mini = (1LL * nums[i] * ncr[i][x - 1]) % mod;
        int maxi = (1LL * nums[i] * ncr[n - i - 1][x - 1]) % mod;

        ans=(ans+mini)%mod;
        ans=(ans+maxi)%mod;
        }
     }
     return ans%mod;

    }
};