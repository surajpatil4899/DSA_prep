class Solution{
  public:
  int dp[1005];
    int calc(vector<int> &prices, int len){
        if(len==0) return 0;
        
        if(dp[len] != -1) return dp[len];
        
        int ans  = 0;
        for(int cut = 1;cut<=prices.size();cut++){
            if(len-cut >= 0){
                ans = max(ans, calc(prices,len-cut) + prices[cut-1]);
            }
        }
        return dp[len] = ans;
    }
    int cutRod(int price[], int n) {
        //code here
        memset(dp, -1, sizeof(dp));
        vector<int> prices(price, price+n);
        return calc(prices,n);
    }
};