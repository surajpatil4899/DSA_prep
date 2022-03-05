class Solution {
public:
    int dp[101];
    int solve(int i,string &s){
        if(i==s.size()) return 1;
        if(s[i]=='0') return 0;
        
        if(dp[i] != -1) return dp[i];
        
        int count = 0;
        count += solve(i+1,s); 
        if(i+2<=s.size() && stoi(s.substr(i,2))<=26)
        count += solve(i+2, s);
        
        return dp[i] = count;
    }
    int numDecodings(string s) {
        memset(dp, -1 , sizeof(dp));
        return solve(0,s);
    }
};