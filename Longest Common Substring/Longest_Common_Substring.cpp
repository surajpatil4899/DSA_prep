  int longestCommonSubstr (string t1, string t2, int n, int m)
    {
      int dp[1001][1001];
        for(int i=0;i<n+1;i++){
            for(int j=0;j<m+1;j++)
                if(j==0 || i==0) dp[i][j] = 0;
        }
        int result = 0;
      for(int i=1;i<n+1;i++){
           for(int j=1;j<m+1;j++){
               if(t1[i-1]==t2[j-1]){
                   dp[i][j] = 1 + dp[i-1][j-1];
                    result = max(result, dp[i][j]);    
               }
               else{
                   dp[i][j] = 0;
               }
           }
      }
        
        return result;
    }