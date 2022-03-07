class Solution {
public:
    int dp[101];
    int solve(int i,vector<int> &num){
        if(i>=num.size()) return 0;
        
        if(dp[i] != -1) return dp[i];
        
        int left = num[i] + solve(i+2,num);
        int right = solve(i+1,num);
        
        return dp[i] = max(left,right);
    }
    int rob(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
      return solve(0,nums);  
    }
};