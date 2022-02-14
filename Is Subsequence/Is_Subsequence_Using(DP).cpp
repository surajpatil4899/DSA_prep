class Solution {
public:
    int dp[101][10001];
    bool check(string &s, string &t,int n, int m){
        if(n==0) return true;
        if(m==0) return false;
        
        if(dp[n][m] != -1) return dp[n][m];
        
        if(s[n-1]==t[m-1])
            return dp[n][m] = check(s,t,n-1,m-1);
        
        return dp[n][m] = check(s,t,n,m-1);
            
    }
    bool isSubsequence(string s, string t) {
        memset(dp, -1, sizeof(dp));
       int n = s.size();
        int m = t.size();
        
        return check(s,t,n,m);
    }
};