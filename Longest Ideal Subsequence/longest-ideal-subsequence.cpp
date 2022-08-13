class Solution {
public:
    int dp[100005][150];
    
    int solve(int& k,int i,int prev,string& s){
        if(i >= s.size()) return 0;
        
        if(dp[i][prev] != -1) return dp[i][prev];
        
        int take = 0, nottake = 0;
        if(prev==0 || abs(prev-s[i]) <= k)
            take = 1 + solve(k,i+1,s[i],s);
        
        nottake = solve(k,i+1,prev,s);
        
        return dp[i][prev] = max(take, nottake);
    }
    
    int longestIdealString(string s, int k) {
         memset(dp, -1, sizeof(dp));
        
        return solve(k,0,0,s);
    }
};