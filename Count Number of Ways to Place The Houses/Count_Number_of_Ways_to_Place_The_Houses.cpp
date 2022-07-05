class Solution {
public:
    const int mod = 1e9+7;
    int countHousePlacements(int n) {
       vector<long long> dp(n+1);
        dp[0] = 1;
        for(int i=1;i<=n;i++){
            dp[i] = dp[i-1] + (i-2 >= 0 ? dp[i-2] : 1);
            dp[i] %= mod;
        }
        
        return (dp[n] * dp[n]) % mod;
    }
};