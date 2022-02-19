class Solution {
public:
    int dp[501][501];
    int solve(string &s1,string &s2,int i,int j){
        if(i==0) return j;
        if(j==0) return i;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        if(s1[i-1]==s2[j-1])
            return dp[i][j] = solve(s1,s2,i-1,j-1);
        
        return dp[i][j] = 1 + min(solve(s1,s2,i,j-1), min(solve(s1,s2,i-1,j),
       solve(s1,s2,i-1,j-1)));
    }
    int minDistance(string word1, string word2) {
        memset(dp, -1, sizeof(dp));
        return solve(word1,word2,word1.size(),word2.size());
    }
};