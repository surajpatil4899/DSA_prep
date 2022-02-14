class Solution {
public:
    int dp[5005][305];
    int comb(vector<int> &coins, int amount,int index){
        if(amount==0) return 1;
        if(index<0) return 0;
        
        if(dp[amount][index] != -1) return dp[amount][index];
        int ans = 0;
        
        for(int coin_amount = 0;coin_amount<=amount;coin_amount+=coins[index]){
            ans += comb(coins,amount-coin_amount,index-1);
        }
        
        return dp[amount][index] = ans;
    } 
    int change(int amount, vector<int>& coins) {
        memset(dp, -1, sizeof(dp));
        
        return comb(coins,amount,coins.size()-1);
    }
};