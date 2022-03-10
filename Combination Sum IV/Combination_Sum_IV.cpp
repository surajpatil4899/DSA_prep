class Solution {
public:
    int dp[1001];
    int solve(vector<int>& nums, int target){
        if(target==0) return 1;
        
        if(dp[target] != -1) return dp[target];
        
        int ans = 0;
        for(auto &num:nums){
            if(num<=target) ans += solve(nums,target-num);
        }
        
        return dp[target] = ans;
    }
    int combinationSum4(vector<int>& nums, int target) {
        memset(dp, -1, sizeof(dp));
      return solve(nums,target);
    }
};