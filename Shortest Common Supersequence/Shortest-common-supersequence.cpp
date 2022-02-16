class Solution
{
    public:
    int dp[101][101];
   int lcs(string s1,string s2,int i,int j){
       if(i==0 || j==0) return 0;
       
       if(dp[i][j] != -1) return dp[i][j];
       
       if(s1[i-1]==s2[j-1])
       return dp[i][j] = 1 + lcs(s1,s2,i-1,j-1);
       else{
           return dp[i][j] = max(lcs(s1,s2,i-1,j), lcs(s1,s2,i,j-1));
       }
   }
    int shortestCommonSupersequence(string X, string Y, int m, int n)
    {
        memset(dp, -1, sizeof(dp));
      int ans = lcs(X,Y,m,n);
      return (m+n) - ans;
    }
};