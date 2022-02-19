class Solution{
public:
 int dp[1001][801];
int mod = 1000000007;
     int solve(int n,int k){
          if(k>n) return 0;
          if(k==0 || k==n) return 1;
          
          if(dp[n][k] != -1) return dp[n][k]%mod;
          
          return dp[n][k] = (solve(n-1,k-1)%mod + solve(n-1,k)%mod)%mod;
      }
    int nCr(int n, int r){
        // code here
        memset(dp, -1, sizeof(dp));
        return solve(n,r);
    }
};