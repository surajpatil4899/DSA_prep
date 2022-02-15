class Solution {
public:
    int dp[10001][201];
    bool func(vector<int> &nums,int sum,int i){
        if(sum==0) return true;
        if(i < 0) return false;
        
        if(dp[sum][i] != -1) return dp[sum][i];
        
        bool isPoss = func(nums,sum,i-1);
        
        if(sum-nums[i] >= 0)
         isPoss |= func(nums,sum-nums[i],i-1);
        
        return dp[sum][i] = isPoss;
    }
    
    bool canPartition(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum%2 != 0) return false;
        sum /= 2;
        
        return func(nums,sum,nums.size()-1);
    }
};