class Solution {
public:
   
//     int lcs(int i,int j,string &s1,string &s2){
//         if(j < 0 || i < 0) return 0;
        
//         if(dp[i][j] != -1) return dp[i][j];
//         if(s1[i]==s2[j])
//             return dp[i][j] = 1 + lcs(i-1,j-1,s1,s2);
//         else    
//         return dp[i][j] = max(lcs(i-1,j,s1,s2),lcs(i,j-1,s1,s2));
       
        
        
//     }
    int longestCommonSubsequence(string t1, string t2) {
         int dp[1001][1001];
        for(int i=0;i<t1.size()+1;i++){
            for(int j=0;j<t2.size()+1;j++)
                if(j==0 || i==0) dp[i][j] = 0;
        }   
      for(int i=1;i<t1.size()+1;i++){
           for(int j=1;j<t2.size()+1;j++){
               if(t1[i-1]==t2[j-1])
                   dp[i][j] = 1 + dp[i-1][j-1];
               else{
                   dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
               }
           }
      }
        
        return dp[t1.size()][t2.size()];
    }
};