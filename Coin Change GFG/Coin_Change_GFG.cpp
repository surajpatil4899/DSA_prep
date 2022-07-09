class Solution {
  public:
  long long int dp[1001][1001];
  long long int solve(int a[],int m,int n){
       if(n==0) return 1;
       if(m==-1 && n>0) return 0;
       if(n<0) return 0;
       
       if(dp[m][n] != -1) return dp[m][n];
     
      return dp[m][n] = solve(a,m,n-a[m]) + solve(a,m-1,n);
  }     

    long long int count(int s[], int m, int n) {
        memset(dp, -1, sizeof(dp));
      return solve(s,m-1,n);
    }
};