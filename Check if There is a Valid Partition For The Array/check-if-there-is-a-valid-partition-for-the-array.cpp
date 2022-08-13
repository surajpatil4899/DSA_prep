class Solution {
public:
    int dp[100005];
    bool solve(int i,vector<int>& nums){
        if(i>=nums.size()) return true;
        
        if(dp[i] != -1) return dp[i];
        
        if(i+1 <nums.size() && nums[i]==nums[i+1]){
            if(solve(i+2,nums)) return true;
            if(i+2 < nums.size() && nums[i+1]==nums[i+2])
            if(solve(i+3,nums)) return true;
        }
        
        if(i+2 < nums.size() && nums[i] == nums[i+1]-1 && nums[i] == nums[i+2]-2)
           if(solve(i+3,nums)) return true;
        
        return dp[i] = false;
    }
    bool validPartition(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return solve(0,nums);
    }
};