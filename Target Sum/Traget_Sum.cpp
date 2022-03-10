class Solution {
public:
     int dp[21][2001];
 
    int dfs(int index, vector<int>& nums, int &S, int sum)
    {
        
        if(index==nums.size())
            return sum==S?1:0;

        if(dp[index][sum+1000]!=-1) return dp[index][sum+1000];
        
        int count = 0;
        
        
        count+= dfs(index+1,nums,S,sum+nums[index]);
        count+= dfs(index+1,nums,S,sum-nums[index]);
        
        return dp[index][sum+1000] = count;
    }
    
    int findTargetSumWays(vector<int>& nums, int S) {
        
  
        memset(dp,-1,sizeof(dp));
 
        return dfs(0,nums,S,0);
    }
};