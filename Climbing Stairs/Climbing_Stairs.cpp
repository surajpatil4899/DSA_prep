class Solution {
public:
    int dp[50];
    int way(int n){
        if(n==0) return 0;
        if(n==1) return 1;
        if(n==2) return 2;
      if(dp[n] != -1) return dp[n];  
        return dp[n] = way(n-1) + way(n-2);
    }
    int climbStairs(int n) {
        memset(dp, -1, sizeof(dp));
        return way(n);
    }
};