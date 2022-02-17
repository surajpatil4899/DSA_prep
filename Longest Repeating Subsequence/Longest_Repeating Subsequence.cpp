	public:
	    int dp[1001][1001];
	    int lrs(string &s1,string &s2,int i,int j){
	        if(i==0 || j==0) return 0;
	        
	        if(dp[i][j] != -1) return dp[i][j];
	        
	        if(s1[i-1]==s2[j-1] && i!=j)
	        return dp[i][j] = 1 + lrs(s1,s2,i-1,j-1);
	        else{
	            return dp[i][j] = max(lrs(s1,s2,i-1,j), lrs(s1,s2,i,j-1));
	        }
	    }
		int LongestRepeatingSubsequence(string str){
		    memset(dp, -1, sizeof(dp));
		    int n = str.size();
		    return lrs(str,str,n,n);
		}