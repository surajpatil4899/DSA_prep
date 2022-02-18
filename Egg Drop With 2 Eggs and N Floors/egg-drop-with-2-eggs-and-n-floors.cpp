class Solution {
public:
    int dp[1001][3];
    int solve(int f,int e){
        if(e==1) return f;
        if(f<=1) return f;
        
        if(dp[f][e] != -1) return dp[f][e];
        
        int mn = INT_MAX;
        for(int k=1;k<f;k++){
            int temp = 1 + max(solve(k-1,e-1), solve(f-k,e));
            mn = min(mn, temp);
        }
        
        return dp[f][e] = mn;
    }
    int twoEggDrop(int n) {
        memset(dp, -1, sizeof(dp));
        return solve(n,2);
    }
};