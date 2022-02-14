class Solution {
public:
    int dp[10001];
    int req(vector<int> &coins,int a){
        if(a==0) return 0;
        if(dp[a] != -1) return dp[a];
        int ans = INT_MAX;
        for(int coin: coins){
            if(a-coin >= 0)
                ans = min(ans+0LL, req(coins,a-coin)+1LL);
        }
        
        return dp[a] = ans;
    }
    int coinChange(vector<int>& coins, int amount) {
        memset(dp, -1, sizeof(dp));
        int ans = req(coins,amount);
        if(ans==INT_MAX) return -1;
        return ans;
    }
};