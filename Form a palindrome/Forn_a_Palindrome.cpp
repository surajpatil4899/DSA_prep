class Solution{
  public:
   int dp[1001][1001];
	    int lcs(string &s1,string &s2,int i,int j){
	        if(i==0 || j==0) return 0;
	        
	        if(dp[i][j] != -1) return dp[i][j];
	        
	        if(s1[i-1]==s2[j-1])
	        return dp[i][j] = 1 + lcs(s1,s2,i-1,j-1);
	        else{
	            return dp[i][j] = max(lcs(s1,s2,i-1,j), lcs(s1,s2,i,j-1));
	        }
	    }
    int countMin(string str){
    memset(dp, -1, sizeof(dp));
    string temp = str;
    reverse(str.begin(), str.end());
    int n = str.size();
    
    return n - lcs(temp,str,n,n);
    }
};