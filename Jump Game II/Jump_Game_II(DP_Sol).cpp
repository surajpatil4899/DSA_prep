class Solution {
public:
    int dp[10001];
  long long int jumps(vector<int> &nums,int index,int end){
        if(index>=end) return 0;
        
       long long int ans = INT_MAX;
       if(dp[index] != -1) return dp[index];
       
        for(int i=1;i<=nums[index];i++){
            ans = min(ans, 1+jumps(nums,index+i,end));
        }
        return dp[index] = ans;
    }
    
    int jump(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
       return jumps(nums,0,nums.size()-1);      
    }
};