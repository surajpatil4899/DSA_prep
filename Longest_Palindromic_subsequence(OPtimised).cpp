class Solution {
public:
    	 int dp[1001][1001];
   int lcs(string &s1,string &s2,int i,int j){
       if(i==0 || j==0) return 0;
       
       if(dp[i][j] != -1) return dp[i][j];
       
       if(s1[i-1]==s2[j-1])
       return dp[i][j] = 1 + lcs(s1,s2,i-1,j-1);
       else{
            // return dp[i][j] = max(lcs(s1,s2,i-1,j), lcs(s1,s2,i,j-1));
           int left,right;
           if(dp[i-1][j] != -1) left = dp[i-1][j];
           else{
               left = lcs(s1,s2,i-1,j);
               dp[i-1][j] = left;
           }
           if(dp[i][j-1] != -1) right = dp[i][j-1];
           else{
               right = lcs(s1,s2,i,j-1);
               dp[i][j-1] = right;
           }
           
           return dp[i][j] = max(left,right);
       }
   }
    int longestPalindromeSubseq(string s) {
        memset(dp, -1, sizeof(dp));
        string temp = s;
        reverse(s.begin(), s.end());
        int size = s.size();
        
        return lcs(temp,s,size,size);
        
    }
};