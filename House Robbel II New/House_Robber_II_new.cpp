class Solution {
public:
    int dp[101][2];
    int solve(vector<int> &nums, int i,int n,int first){
        if(i>=n || (i==n-1 && first)) return 0;
        
        if(dp[i][first] != -1) return dp[i][first];
        
        int rob=0,notrob=0;
        if(i==0) rob = nums[i] + solve(nums,i+2,n,1);
        else rob = nums[i] + solve(nums,i+2,n,first);
        notrob = solve(nums,i+1,n,first);
      
        return dp[i][first] = max(rob,notrob);
    }
    int rob(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        int n = nums.size();
        return solve(nums,0,n,0);
    }
};